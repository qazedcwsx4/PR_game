#include "Server.h"

Server::Server(const char *addr, const int port) {
    serverTCP = new ServerTCP(addr, port);
    if (serverTCP->init() != 0) std::cout << "INIT ERROR\n";
}

void Server::loop() {
    targetTickrate = 120;

    sf::Time targetTickTime = sf::microseconds(1000000 / targetTickrate);
    sf::Time targetStatTime = sf::milliseconds(1000);

    sf::Clock clock;

    sf::Time prevTick = clock.getElapsedTime();
    sf::Time prevStat = clock.getElapsedTime();

    int ticks = 0;

    while (!shouldQuit) {
        if (clock.getElapsedTime() - prevTick >= targetTickTime) {
            int skipped =
                    ((clock.getElapsedTime() - prevTick).asMilliseconds() - (targetTickTime.asMilliseconds() / 2)) /
                    targetTickTime.asMilliseconds();
            if (skipped > 0) {
                std::cout << "SKIPPING TICKS " << skipped << std::endl;
            } else {
                tick(skipped);
            }
            prevTick = clock.getElapsedTime();
            ticks++;
        }


        //handle FPS
        if (clock.getElapsedTime() - prevStat >= targetStatTime) {
            float TPS = (float) ticks * (float) 1000.0f / (float) (clock.getElapsedTime() - prevStat).asMilliseconds();

            prevStat = clock.getElapsedTime();

            std::cout << TPS << " " << serverTCP->getSimpleClientList().size() << "/4 " << "\n";

            ticks = 0;
        }

        sf::sleep(sf::microseconds(505));
    }
}

void Server::tick(int skipped) {
    //std::cout << serverTCP->getSimpleClientList().size();
}

Server::~Server() {
    delete serverTCP;
}
