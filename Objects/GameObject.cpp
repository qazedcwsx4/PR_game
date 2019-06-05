#include "GameObject.h"
#include "Wall.h"
#include "Bullet.h"

bool GameObject::collisionBroad(GameObject &gameObject) {
    return this->shape->getGlobalBounds().intersects(gameObject.shape->getGlobalBounds());
}

GameObject::GameObject(sf::RenderWindow &renderWindow) : renderWindow(renderWindow) {

}

sf::Vector2f GameObject::getPosition() {
    return shape->getPosition();
}

void GameObject::setAngle(float angle) {
    shape->setRotation(angle);
}

void GameObject::moveBy(float x, float y) {
    shape->move(x, y);
}

float GameObject::getAngle() {
    return shape->getRotation();
}

bool GameObject::collisionNarrow(GameObject &gameObject) {
    if (typeid(Wall) == typeid(gameObject)) {
        auto wall = dynamic_cast<Wall &> (gameObject);
        auto thisPos = this->getPosition();

        //vertical walls
        if (wall.getX1() - wall.getX2() == 0) {
            if (abs(wall.getX1() - thisPos.x) <= 5 + this->getRadius()) return true;
            else return false;
        }

        //
        float dist = sqrt((pow((wall.getX1() + wall.getX2()) / 2 - thisPos.x, 2) +
                           (pow((wall.getY1() + wall.getY2()) / 2 - thisPos.y, 2))));
        if (dist >= wall.getLength() / 2 + this->getRadius())
            return false;
        float A = (wall.getY2() - wall.getY1()) / (wall.getX2() - wall.getX1());
        float B = wall.getY2() - wall.getX2() * A;
        float r = abs(A * thisPos.x - thisPos.y + B) / sqrt(A * A + 1);
        if (r <= this->getRadius() + 5) return true;
        else return false;
    }
    if (typeid(Bullet) == typeid(gameObject)) {
        auto bullet = dynamic_cast<Bullet &> (gameObject);
        auto thisPos = this->getPosition();
        auto otherPos = bullet.getPosition();
        if (sqrt((thisPos.x - otherPos.x) * (thisPos.x - otherPos.x) +
                 (thisPos.y - otherPos.y) * (thisPos.y - otherPos.y)) <= this->getRadius() + bullet.getRadius()) {
            return true;
        } else return false;
    }
    return false;
}

float GameObject::getRadius() {
    return 0;
}

bool GameObject::operator==(const GameObject &gameObject) {
    return (this == &gameObject);
}


