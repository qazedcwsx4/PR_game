#ifndef UNTITLED_LOGIC_H
#define UNTITLED_LOGIC_H

#include "Renderer.h"
#include "../Objects/Map.h"


class Renderer;
class Map;

class Logic {
private:
    Renderer *renderer;
    Map *map;
public:
    Logic(Renderer *renderer);

    ~Logic();

    void tick(int skipped);

    Renderer *getRenderer();

    Map *getMap();
};


#endif
