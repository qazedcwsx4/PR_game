#ifndef UNTITLED_LOGIC_H
#define UNTITLED_LOGIC_H

#include "Renderer.h"
#include "../Objects/Map.h"
#include "../Objects/Player.h"
#include "../Objects/Bullet.h"
#include <list>
#include <llogl.h>

class Renderer;

class Map;

class Logic {
private:
    Renderer *renderer;
    Map *map;
    std::list<Player> players;
    std::list<Bullet> bullets;
    Player *myPlayer;
    ClientTCP *clientTCP;
public:
    Logic(Renderer *renderer, ClientTCP *clientTCP);

    ~Logic();

    void tick(int skipped);

    Renderer *getRenderer();

    Map *getMap();

    void tryMoveBy(GameObject &gameObject, float x, float y);

    std::list<Player> &getPlayers();

    std::list<Bullet> &getBullets();
};


#endif
