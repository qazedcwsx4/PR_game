//
// Created by qaze on 31/05/2019.
//

#ifndef GAME_MAP_H
#define GAME_MAP_H


#include "Wall.h"
#include <vector>
#include "../Game/Renderer.h"

class Map {
private:
    std::vector<Wall> walls;
    sf::RenderWindow &renderWindow;
public:
    explicit Map(sf::RenderWindow &renderWindow);

    void render();

    std::vector<Wall> &getWalls();
};


#endif //GAME_MAP_H
