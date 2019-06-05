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
    if (!inProgress) {
        if (serverTCP->getSimpleClientList().size() == 2) {
            inProgress = true;
            std::cout << "GAME STARTING\n";
            Sleep(1000);
            serverTCP->sendAll("", 1, 1);
        }
    } else {
        for (auto client : serverTCP->getSimpleClientList()) {
            while (!client.fullData.messages.empty()) {
                Message *message = serverTCP->getMessage(client);
                switch (message->type) {
                    //handle player data
                    case 2: {
                        //basically broadcast
                        for (auto clientToSend : serverTCP->getSimpleClientList()) {
                            if (client.socket != clientToSend.socket) {
                                auto playerModel = reinterpret_cast<PlayerModel *> (message->data);
                                playerModel->number = client.socket;
                                serverTCP->send(clientToSend, reinterpret_cast<char *>(playerModel),
                                                sizeof(PlayerModel), 2);
                            }
                        }
                        break;
                    }
                    /*case 3: {
                        //basically broadcast
                        for (auto clientToSend : serverTCP->getSimpleClientList()) {
                            if (client.socket != clientToSend.socket) {
                                serverTCP->send(clientToSend, reinterpret_cast<char *>(message->data), message->size,
                                                3);
                            }
                        }
                        break;
                    }*/
                }
                delete message;
            }
        }
    }
}


Server::~Server() {
    delete serverTCP;
}
