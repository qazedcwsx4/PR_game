//
// Created by qaze on 31/05/2019.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H
#include "GameObject.h"


class Player : public GameObject{
private:
    bool myPlayer;
public:
    Player(sf::RenderWindow &renderWindow, float x, float y, bool myPlayer);
    bool collisionNarrow(GameObject &gameObject) override;
    void render() override;
    ~Player();

    bool isMyPlayer() const;
};


#endif //GAME_PLAYER_H
