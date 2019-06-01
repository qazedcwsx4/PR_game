//
// Created by qaze on 31/05/2019.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include "GameObject.h"


class Player : protected GameObject{
public:
    bool myPlayer;
    Player(sf::RenderWindow &renderWindow, float x, float y, bool myPlayer);
    bool collisionNarrow(GameObject &gameObject) override;
    void render() override;
    ~Player();
};


#endif //GAME_PLAYER_H
