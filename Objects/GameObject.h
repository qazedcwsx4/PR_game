#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject {
protected:
    sf::RenderWindow &renderWindow;
    sf::Shape *shape;
    explicit GameObject(sf::RenderWindow &renderWindow);

public:
    virtual bool collisionBroad(GameObject &gameObject);

    virtual bool collisionNarrow(GameObject &gameObject) = 0;

    virtual void render() = 0;

    virtual ~GameObject() = default;
};


#endif //GAME_GAMEOBJECT_H
