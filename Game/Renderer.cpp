#include "Renderer.h"

Renderer::Renderer(unsigned int width, unsigned int height, const std::string &title, sf::ContextSettings settings) :
        renderWindow(sf::VideoMode(width, height), title, sf::Style::Default, settings) {
}

void Renderer::render(double dT) {
    renderWindow.clear();
    logic->getMap()->render();
    for (Player &player : logic->getPlayers()) {
        player.render();
    }
    for (Bullet &bullet : logic->getBullets()) {
        bullet.render();
    }
    renderWindow.display();
}

sf::RenderWindow &Renderer::getRenderWindow() {
    return renderWindow;
}

void Renderer::setLogic(Logic *logic) {
    Renderer::logic = logic;
}
