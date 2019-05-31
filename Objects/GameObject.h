#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

struct BoundingBox {
    float x1, x2;
    float y1, y2;
};

class GameObject {
protected:
    sf::RenderWindow &renderWindow;
    BoundingBox box;
    explicit GameObject(sf::RenderWindow &renderWindow);

public:
    virtual bool collisionBroad(GameObject &gameObject);

    virtual bool collisionNarrow(GameObject &gameObject) = 0;

    virtual void render() = 0;

    virtual ~GameObject() = default;
};


#endif //GAME_GAMEOBJECT_H
