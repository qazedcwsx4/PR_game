//
// Created by qaze on 31/05/2019.
//

#ifndef GAME_WALL_H
#define GAME_WALL_H

#include "GameObject.h"
#include <math.h>

class Wall : public GameObject {
private:
    float x1, x2;
    float y1, y2;
    float normal;
    float length;
    float width;
public:
    Wall(sf::RenderWindow &renderWindow, float x1, float x2, float y1, float y2);

    void render() override;

    bool collisionNarrow(GameObject &gameObject) override;

    float getX1() const;

    float getX2() const;

    float getY1() const;

    float getY2() const;

    float getNormal() const;

    float getLength() const;
};


#endif //GAME_WALL_H
