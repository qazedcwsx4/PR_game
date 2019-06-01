#include <thread>
#include <iostream>
#include "Logic.h"

Logic::Logic(Renderer *renderer) : renderer(renderer) {
    map = new Map(renderer->getRenderWindow());
    map->render();
    players.emplace_back(renderer->getRenderWindow(), 200, 200);
}

Renderer *Logic::getRenderer() {
    return renderer;
}

void Logic::tick(int skipped) {
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

