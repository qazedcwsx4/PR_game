#include <thread>
#include <iostream>
#include "Logic.h"

Logic::Logic(Renderer *renderer, ClientTCP *clientTCP) : renderer(renderer), clientTCP(clientTCP) {
    map = new Map(renderer->getRenderWindow());
    map->render();
    players.emplace_back(renderer->getRenderWindow(), 200, 200, true);
    myPlayer = &(players.front());
}

Renderer *Logic::getRenderer() {
    return renderer;
}

void Logic::tick(int skipped) {

    //handle events
    sf::Event event;
    while (renderer->getRenderWindow().pollEvent(event)) {
        //handle events;
        switch (event.type) {
            // window closed
            case sf::Event::Closed:
                renderer->getRenderWindow().close();
                break;

            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left) {
                    bullets.emplace_back(renderer->getRenderWindow(), *myPlayer);
                    auto bulletModel = bullets.back().exportData();
                    clientTCP->send(reinterpret_cast<char *>(&bulletModel), sizeof(BulletModel), 3);
                }
        }
    }

    //handle net events;
    Message *message;
    while (true) {
        message = clientTCP->getMessage();
        if (message == nullptr) break;
        switch (message->type) {
            //POZYCJA GRACZA
            case 2: {
                auto playerModel = reinterpret_cast<PlayerModel *> (message->data);
                auto found = false;
                for (Player &player : players) {
                    if (player.getPlayerNumber() == playerModel->number) {
                        player.applyData(*playerModel);
                        found = true;
                        break;
                    }
                }

                //create new player
                if (!found) {
                    players.emplace_back(renderer->getRenderWindow(), 0, 0, false);
                    players.back().applyData(*playerModel);
                    players.back().setPlayerNumber(playerModel->number);
                }
                break;
            }
            case 3: {
                auto bulletModel = reinterpret_cast<BulletModel *> (message->data);
                bullets.emplace_back(renderer->getRenderWindow(), *bulletModel);
                break;
            }
            default: {
                std::cout << "UNKNOWN NETWORK MESSAGE";
                break;
            }
        }
        delete message;
    }


    //get inputs
    sf::Vector2f mousePosition = (sf::Vector2f) sf::Mouse::getPosition(renderer->getRenderWindow());

    //process players
    for (Player &player : players) {
        if (player.isMyPlayer()) {
            sf::Vector2f myPlayerPosition = player.getPosition();
            float myPlayerAngle;

            //terribly ugly myPlayer angle calculation
            if (mousePosition.y <= myPlayerPosition.y)
                myPlayerAngle =
                        -atan((mousePosition.x - myPlayerPosition.x) / (mousePosition.y - myPlayerPosition.y)) * 180 /
                        3.14159265;
            else
                myPlayerAngle =
                        -atan((mousePosition.x - myPlayerPosition.x) / (mousePosition.y - myPlayerPosition.y)) * 180 /
                        3.14159265 + 180;
            player.setAngle(myPlayerAngle);
            bool playerMoved = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                tryMoveBy(player, -3, 0);
                playerMoved = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                tryMoveBy(player, 3, 0);
                playerMoved = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                tryMoveBy(player, 0, -3);
                playerMoved = true;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                tryMoveBy(player, 0, 3);
                playerMoved = true;
            }
            if (playerMoved) {
                auto playerData = player.exportData();
                clientTCP->send(reinterpret_cast<char *>(&playerData), sizeof(PlayerModel), 2);
            }

        }
    }

    //process bullets
    for (Bullet &bullet : bullets) {
        tryMoveBy(bullet, bullet.getSpeed() * cos((bullet.getAngle() - 90) * 3.14159265 / 180),
                  bullet.getSpeed() * sin((bullet.getAngle() - 90) * 3.14159265 / 180));
    }
}

Map *Logic::getMap() {
    return map;
}

Logic::~Logic() {
    delete map;
}

std::list<Player> &Logic::getPlayers() {
    return players;
}

std::list<Bullet> &Logic::getBullets() {
    return bullets;
}

//collision detection
void Logic::tryMoveBy(GameObject &gameObject, float x, float y) {
    gameObject.moveBy(x, y);
    for (Wall &go : map->getWalls()) {
        if (gameObject.collisionBroad(go)) {
            if (gameObject.collisionNarrow(go)) {
                if (typeid(Bullet) == typeid(gameObject)) {
                    Bullet &bullet = dynamic_cast<Bullet &> (gameObject);
                    if (bullet.getSpeed() > 8) bullets.remove(bullet);
                    gameObject.moveBy(-x, -y);
                    bullet.setSpeed(bullet.getSpeed() * 2);
                    gameObject.setAngle(go.getNormal() + (go.getNormal() - gameObject.getAngle()));
                } else if (typeid(Player) == typeid(gameObject)) {
                    gameObject.moveBy(-x, -y);
                }
                return;
            }
        }
    }
    for (GameObject &go : bullets) {
        if (gameObject.collisionBroad(go)) {
            if (gameObject.collisionNarrow(go)) {
                return;
            }
        }
    }
}

