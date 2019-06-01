//
// Created by qaze on 01/06/2019.
//

#include "Textures.h"

sf::Texture *Textures::playerTexture = nullptr;

void Textures::loadAll() {
    playerTexture = new sf::Texture;
    if (!playerTexture->loadFromFile("../Resources/player.png")) {
        std::cout << "ERROR LOADING TEXTURES\n";
    }
    playerTexture->setSmooth(true);
}

sf::Texture *Textures::getPlayerTexture() {
    return playerTexture;
}
