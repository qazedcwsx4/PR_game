#include "GameObject.h"

bool GameObject::collisionBroad(GameObject &gameObject) {
    return this->shape->getGlobalBounds().intersects(gameObject.shape->getGlobalBounds());
}

GameObject::GameObject(sf::RenderWindow &renderWindow) : renderWindow(renderWindow) {

}
