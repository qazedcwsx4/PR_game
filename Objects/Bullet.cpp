//
// Created by qaze on 04/06/2019.
//

#include "Bullet.h"

Bullet::Bullet(sf::RenderWindow &renderWindow, Player &player) : GameObject(renderWindow), angle(player.getAngle()) {
    shape = new sf::CircleShape(50);
    shape->setTexture(Textures::getMyBulletTexture());
    shape->setOrigin(50, 50);
    auto playerPos = player.getPosition();
    shape->setPosition(playerPos.x, playerPos.y);
    shape->setScale(0.1, 0.1);
}

Bullet::~Bullet() {

}



bool Bullet::collisionNarrow(GameObject &gameObject) {
    return false;
}

void Bullet::render() {
    renderWindow.draw(*shape);
}

float Bullet::getAngle() {
    return angle;
}
