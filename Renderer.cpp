#include "Renderer.h"

Renderer::Renderer(Logic *logic, unsigned int width, unsigned int height, const std::string &title) :
        renderWindow(sf::VideoMode(width, height), title), logic(logic) {
}

void Renderer::render(double dT) {
    renderWindow.clear();
    renderWindow.display();
}

sf::RenderWindow &Renderer::getRenderWindow() {
    return renderWindow;
}
