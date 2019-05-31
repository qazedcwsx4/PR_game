//
// Created by qaze on 31/05/2019.
//

#include "Wall.h"

Wall::Wall(sf::RenderWindow &renderWindow, float x1, float y1, float x2, float y2) : x1(x1), x2(x2), y1(y1), y2(y2),
                                                                                     GameObject(renderWindow) {
    //if (x1 > x2) std::swap(x1, x2);
    //if (y1 > y2) std::swap(y1, y2);

    box.x1 = x1;
    box.x2 = x2;
    box.y1 = y1;
    box.y2 = y2;
    float angle = atan((y2 - y1) / (x2 - x1)) * 180 / 3.14159265;
    float length = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))+10;
    float width = 10;
    shape = sf::RectangleShape(sf::Vector2f(length, width));
    shape.setOrigin(5, 5);
    //shape.move(0, -width / 2);
    shape.setRotation(angle);
    shape.setPosition(x1, y1);
}

void Wall::render() {
    renderWindow.draw(shape);
}

bool Wall::collisionNarrow(GameObject &gameObject) {
    return false;
}
