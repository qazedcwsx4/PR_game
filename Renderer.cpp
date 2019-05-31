#include "Renderer.h"

Renderer::Renderer(unsigned int width, unsigned int height, const std::string &title) :
        renderWindow(sf::VideoMode(width, height), title) {
}

void Renderer::render(double dT) {
    renderWindow.clear();
    renderWindow.display();
}