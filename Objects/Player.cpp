//
// Created by qaze on 31/05/2019.
//

#include "Player.h"
#include "../Game/Textures.h"
#include "Wall.h"
#include "Bullet.h"
#include <math.h>

Player::Player(sf::RenderWindow &renderWindow, float x, float y, bool myPlayer) : GameObject(renderWindow),
                                                                                  myPlayer(myPlayer) {
    shape = new sf::CircleShape(50);
    if (myPlayer) shape->setTexture(Textures::getMyPlayerTexture());
    else shape->setTexture(Textures::getPlayerTexture());
    shape->setOrigin(50, 50);
    shape->setPosition(x, y);
    shape->setScale(0.33, 0.33);
}

void Player::render() {
    renderWindow.draw(*shape);
}

Player::~Player() {

}

bool Player::isMyPlayer() const {
    return myPlayer;
}

float Player::getRadius() {
    auto circleShape = dynamic_cast<sf::CircleShape *> (shape);
    return circleShape->getRadius() * circleShape->getScale().x;
}
