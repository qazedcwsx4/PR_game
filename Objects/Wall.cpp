//
// Created by qaze on 31/05/2019.
//

#include "Wall.h"

Wall::Wall(sf::RenderWindow &renderWindow, float x1, float y1, float x2, float y2) : x1(x1), x2(x2), y1(y1), y2(y2),
                                                                                     GameObject(renderWindow) {

    float angle = atan((y2 - y1) / (x2 - x1)) * 180 / 3.14159265;
    normal = angle - 90;
    if (normal < 0) normal += 180;
    length = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) + 10;
    width = 10;
    shape = new sf::RectangleShape(sf::Vector2f(length, width));
    shape->setOrigin(5, 5);
    //shape.move(0, -width / 2);
    shape->setRotation(angle);
    shape->setPosition(x1, y1);
}

void Wall::render() {
    renderWindow.draw(*shape);
}

bool Wall::collisionNarrow(GameObject &gameObject) {
    return false;
}

float Wall::getX1() const {
    return x1;
}

float Wall::getX2() const {
    return x2;
}

float Wall::getY1() const {
    return y1;
}

float Wall::getY2() const {
    return y2;
}

float Wall::getNormal() const {
    return normal;
}

float Wall::getLength() const {
    return length;
}
