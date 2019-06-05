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
    speed = 1;
}

Bullet::~Bullet() {

}


void Bullet::render() {
    renderWindow.draw(*shape);
}

float Bullet::getAngle() {
    return angle;
}

void Bullet::setAngle(float angle) {
    this->angle = angle;
}

float Bullet::getRadius() {
    auto circleShape = dynamic_cast<sf::CircleShape *> (shape);
    return circleShape->getRadius() * circleShape->getScale().x;
}

float Bullet::getSpeed() const {
    return speed;
}

void Bullet::setSpeed(float speed) {
    this->speed = speed;
}


