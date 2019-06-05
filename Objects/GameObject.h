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

    virtual bool collisionNarrow(GameObject &gameObject);

    virtual void render() = 0;

    virtual ~GameObject() = default;

    sf::Vector2f getPosition();

    void setPosition(float x, float y);

    virtual float getAngle();

    virtual void setAngle(float angle);

    void moveBy(float x, float y);

    virtual float getRadius();

    bool operator == (const GameObject &gameObject);
};


#endif //GAME_GAMEOBJECT_H
