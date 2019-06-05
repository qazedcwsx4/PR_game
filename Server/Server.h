//
// Created by qaze on 05/06/2019.
//

#ifndef GAME_SERVER_H
#define GAME_SERVER_H

#include <llogl.h>
#include <iostream>
#include <SFML/Graphics.hpp>

class Server {
private:
    unsigned int targetTickrate;
    bool shouldQuit = false;
    ServerTCP *serverTCP;

    void tick(int skipped);
public:
    Server(const char *addr, const int port);

    void loop();

    virtual ~Server();
};


#endif //GAME_SERVER_H
