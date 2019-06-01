//
// Created by qaze on 31/05/2019.
//

#include "Player.h"
#include "../Game/Textures.h"

Player::Player(sf::RenderWindow &renderWindow, float x, float y) : GameObject(renderWindow) {
    shape = new sf::CircleShape(50);
    shape->setTexture(Textures::getPlayerTexture());
    shape->setOrigin(50, 50);
    shape->setPosition(x, y);
    shape->setScale(0.33, 0.33);
}

bool Player::collisionNarrow(GameObject &gameObject) {
    return false;
}

void Player::render() {
    renderWindow.draw(*shape);
}

Player::~Player() {

}
