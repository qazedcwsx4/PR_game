//
// Created by qaze on 27/05/2019.
//

#include <iostream>
#include <synchapi.h>
#include "Game.h"

void Game::launch() {
    waitForStart();
    loop();
}

Game::Game(const char *addr, int port) {
    Textures::loadAll();
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    logic = new Logic(new Renderer(1280, 720, "Game", settings));
    renderer = logic->getRenderer();
    renderer->setLogic(logic);
    clientTCP = new ClientTCP(addr, port);
    if (clientTCP->init() != 0) std::cout << "INIT ERROR\n";
}

void Game::waitForStart() {
    while (true) {
        Message *message = clientTCP->getMessage();
        if (message != nullptr) {
            if (message->type == 1) {
                delete message;
                break;
            }
            delete message;
        }
        Sleep(10);
    }
    std::cout<<"=== 3 ===\n";
    Sleep(1000);
    std::cout<<"=== 2 ===\n";
    Sleep(1000);
    std::cout<<"=== 1 ===\n";
    Sleep(1000);
}

void Game::loop() {
    targetFPS = 144;
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
            double dT = (double) (clock.getElapsedTime() - prevTick).asMicroseconds() / 1000000;
            renderer->render(dT);
            frames++;
            prevFrame = clock.getElapsedTime();
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

Game::~Game() {
    delete clientTCP;
}

