#ifndef UNTITLED_LOGIC_H
#define UNTITLED_LOGIC_H

#include "Renderer.h"

class Renderer;

class Logic {
private:
    Renderer *renderer;
public:
    Logic(Renderer *renderer);

    void tick(int skipped);

    Renderer *getRenderer();
};


#endif
