//
// Created by qaze on 04/06/2019.
//

#ifndef GAME_BULLET_H
#define GAME_BULLET_H

#include "GameObject.h"
#include "Player.h"
#include "../Game/Textures.h"

class Bullet: public GameObject {
public:
    Bullet(sf::RenderWindow &renderWindow, Player &player);

    bool collisionNarrow(GameObject &gameObject) override;

    void render() override;

    virtual ~Bullet();
};


#endif //GAME_BULLET_H
