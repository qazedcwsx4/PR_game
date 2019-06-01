#include <thread>
#include <iostream>
#include "Logic.h"

Logic::Logic(Renderer *renderer) : renderer(renderer) {
    map = new Map(renderer->getRenderWindow());
    map->render();
    players.emplace_back(renderer->getRenderWindow(), 200, 200, true);
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
        }
    }

    //get inputs
    sf::Vector2f mousePosition = (sf::Vector2f) sf::Mouse::getPosition(renderer->getRenderWindow());


    //process players
    for (Player &player : players) {
        if (player.isMyPlayer()) {
            sf::Vector2f myPlayerPosition = player.getPosition();
            float angle;

            //terribly ugly myPlayer angle calculation
            if (mousePosition.y <= myPlayerPosition.y)
                angle = -atan((mousePosition.x - myPlayerPosition.x) / (mousePosition.y - myPlayerPosition.y)) * 180 /
                        3.14159265;
            else
                angle = -atan((mousePosition.x - myPlayerPosition.x) / (mousePosition.y - myPlayerPosition.y)) * 180 /
                        3.14159265 + 180;
            player.setAngle(angle);
        }
    }
//            float angle = -atan((mousePosition.x - myPlayerPosition.x) / (mousePosition.y - myPlayerPosition.y)) * 180 /
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

