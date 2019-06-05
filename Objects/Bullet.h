//
// Created by qaze on 04/06/2019.
//

#ifndef GAME_BULLET_H
#define GAME_BULLET_H

#include "GameObject.h"
#include "Player.h"
#include "Textures.h"

class Bullet : public GameObject {
private:
    float angle;
    float speed;
public:
    Bullet(sf::RenderWindow &renderWindow, Player &player);

    void render() override;

    float getAngle() override;

    virtual ~Bullet();

    float getRadius() override;

    void setAngle(float angle) override;

    float getSpeed() const;

    void setSpeed(float speed);
};


#endif //GAME_BULLET_H
