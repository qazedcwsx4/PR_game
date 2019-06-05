#ifndef UNTITLED_RENDERER_H
#define UNTITLED_RENDERER_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Logic.h"

class Logic;

class Renderer {
private:
    sf::RenderWindow renderWindow;
    Logic *logic;

public:
    Renderer(unsigned int width, unsigned int height, const std::string &title, sf::ContextSettings settings);

    void render(double dT);

    sf::RenderWindow &getRenderWindow();

    void setLogic(Logic *logic);
};


#endif
