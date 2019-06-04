#include <thread>
#include <iostream>
#include "Logic.h"

Logic::Logic(Renderer *renderer) : renderer(renderer) {
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
                    std::cout << "XDD";
                }
        }
    }

    //handle net events;

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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                player.moveBy(-3, 0);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                player.moveBy(3, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                player.moveBy(0, -3);
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                player.moveBy(0, 3);
            }
        }
    }

    //process bullets
    for (Bullet &bullet : bullets) {
        bullet.moveBy(1 * cos((bullet.getAngle()-90)*3.14159265/180), 1 * sin((bullet.getAngle()-90)*3.14159265/180));
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

