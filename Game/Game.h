#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "Renderer.h"
#include "Logic.h"
#include "../Objects/Textures.h"

class Game {
private:
    Renderer *renderer;
    Logic *logic;
    unsigned int targetFPS;
    unsigned int targetTickrate;
    bool shouldQuit = false;
    float framerate;
    float tickrate;
public:
    void launch();

    void loop();
};


#endif
