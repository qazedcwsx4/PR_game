#include "Renderer.h"
#include "../Objects/Wall.h"

Renderer::Renderer(unsigned int width, unsigned int height, const std::string &title) :
        renderWindow(sf::VideoMode(width, height), title){
}

void Renderer::render(double dT) {
    renderWindow.clear();
    logic->getMap()->render();
    renderWindow.display();
}

sf::RenderWindow &Renderer::getRenderWindow() {
    return renderWindow;
}

void Renderer::setLogic(Logic *logic) {
    Renderer::logic = logic;
}
