//
// Created by qaze on 31/05/2019.
//

#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "GameObject.h"

struct PlayerModel {
    float x;
    float y;
    float angle;
    int number;
    //PlayerModel(float x, float y, float angle) : x(x), y(y), angle(angle) {}
};

class Player : public GameObject {
private:
    int playerNumber;
    bool myPlayer;
public:
    Player(sf::RenderWindow &renderWindow, float x, float y, bool myPlayer);

    void render() override;

    ~Player();

    bool isMyPlayer() const;

    float getRadius() override;

    PlayerModel exportData();

    void applyData(PlayerModel &playerModel);

    int getPlayerNumber() const;

    void setPlayerNumber(int playerNumber);
};


#endif //GAME_PLAYER_H
