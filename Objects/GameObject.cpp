#include "GameObject.h"

bool GameObject::collisionBroad(GameObject &gameObject) {
    if (box.x1 >= gameObject.box.x1 && box.x1 <= gameObject.box.x2 && box.y1 >= gameObject.box.y1 &&
        box.y1 <= gameObject.box.y2)
        return true;
    if (box.x2 >= gameObject.box.x1 && box.x2 <= gameObject.box.x2 && box.y1 >= gameObject.box.y1 &&
        box.y1 <= gameObject.box.y2)
        return true;
    if (box.x1 >= gameObject.box.x1 && box.x1 <= gameObject.box.x2 && box.y2 >= gameObject.box.y1 &&
        box.y2 <= gameObject.box.y2)
        return true;
    if (box.x2 >= gameObject.box.x1 && box.x2 <= gameObject.box.x2 && box.y2 >= gameObject.box.y1 &&
        box.y2 <= gameObject.box.y2)
        return true;
    return false;
}

GameObject::GameObject(sf::RenderWindow &renderWindow) : renderWindow(renderWindow) {

}
