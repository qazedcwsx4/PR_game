//
// Created by qaze on 27/05/2019.
//

#include "Game.h"

void Game::launch() {
    sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "Game");
    sf::Clock stoper;
    while (renderWindow.isOpen()) {
        sf::Event event;
        while (renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                renderWindow.close();

        }
        renderWindow.clear();
        renderWindow.display();
    } //while
}
