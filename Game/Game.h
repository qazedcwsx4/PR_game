#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "Renderer.h"
#include "Logic.h"
#include "../Objects/Textures.h"
#include <llogl.h>

class Game {
private:
    Renderer *renderer;
    Logic *logic;
    ClientTCP *clientTCP;
    unsigned int targetFPS;
    unsigned int targetTickrate;
    bool shouldQuit = false;
    float framerate;
    float tickrate;

    void waitForStart();
public:
    Game(const char* addr, int port);

    void launch();

    void loop();

    virtual ~Game();
};


#endif
