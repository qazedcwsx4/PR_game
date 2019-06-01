#ifndef UNTITLED_LOGIC_H
#define UNTITLED_LOGIC_H

#include "Renderer.h"
#include "../Objects/Map.h"
#include "../Objects/Player.h"
#include <list>

class Renderer;
class Map;

class Logic {
private:
    Renderer *renderer;
    Map *map;
    std::list<Player> players;
public:
    Logic(Renderer *renderer);

    ~Logic();

    void tick(int skipped);

    Renderer *getRenderer();

    Map *getMap();

    std::list<Player> &getPlayers();
};


#endif
