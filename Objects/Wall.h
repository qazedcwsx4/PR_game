//
// Created by qaze on 31/05/2019.
//

#ifndef GAME_WALL_H
#define GAME_WALL_H

#include "GameObject.h"
#include <math.h>

class Wall : protected GameObject {
private:
    float x1, x2;
    float y1, y2;
    sf::RectangleShape shape;
public:
    Wall(sf::RenderWindow &renderWindow, float x1,float x2,float y1,float y2);
    void render() override;
    bool collisionNarrow(GameObject &gameObject) override;
};


#endif //GAME_WALL_H
