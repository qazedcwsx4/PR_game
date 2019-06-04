#include "GameObject.h"

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
