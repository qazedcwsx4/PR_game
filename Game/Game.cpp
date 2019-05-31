//
// Created by qaze on 27/05/2019.
//

#include <iostream>
#include <synchapi.h>
#include "Game.h"

void Game::launch() {
    logic = new Logic(new Renderer(1280, 720, "Game"));
    renderer = logic->getRenderer();
    renderer->setLogic(logic);

    loop();
}

void Game::loop() {
    targetFPS = 50;
    targetTickrate = 120;

    sf::Time targetFrameTime = sf::microseconds(1000000 / targetFPS);
    sf::Time targetTickTime = sf::microseconds(1000000 / targetTickrate);
    sf::Time targetStatTime = sf::milliseconds(1000);

    sf::Clock clock;

    sf::Time prevFrame = clock.getElapsedTime();
    sf::Time prevTick = clock.getElapsedTime();
    sf::Time prevStat = clock.getElapsedTime();


    int frames = 0;
    int ticks = 0;

    while (!shouldQuit) {
        if (clock.getElapsedTime() - prevFrame >= targetFrameTime) {
            double dT = (double) (clock.getElapsedTime() - prevFrame).asMicroseconds() / 1000000;
            prevFrame = clock.getElapsedTime();
            frames++;
            renderer->render(dT);
        }
        if (clock.getElapsedTime() - prevTick >= targetTickTime) {
            int skipped =
                    ((clock.getElapsedTime() - prevTick).asMilliseconds() - (targetTickTime.asMilliseconds() / 2)) /
                    targetTickTime.asMilliseconds();
            if (skipped > 0) {
                std::cout << "SKIPPING TICKS " << skipped << std::endl;
            } else {
                logic->tick(skipped);
            }
            prevTick = clock.getElapsedTime();
            ticks++;
        }


        //handle FPS
        if (clock.getElapsedTime() - prevStat >= targetStatTime) {
            float FPS = (float) frames * (float) 1000.0f / (float) (clock.getElapsedTime() - prevStat).asMilliseconds();
            float TPS = (float) ticks * (float) 1000.0f / (float) (clock.getElapsedTime() - prevStat).asMilliseconds();

            prevStat = clock.getElapsedTime();

            std::cout << FPS << " " << TPS << "\n";

            frames = 0;
            ticks = 0;
        }

        sf::sleep(sf::microseconds(505));
    }
}
