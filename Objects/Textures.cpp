//
// Created by qaze on 01/06/2019.
//

#include "Textures.h"

sf::Texture *Textures::playerTexture = nullptr;
sf::Texture *Textures::myPlayerTexture = nullptr;
sf::Texture *Textures::bulletTexture = nullptr;
sf::Texture *Textures::myBulletTexture = nullptr;

void Textures::loadAll() {
    playerTexture = new sf::Texture;
    if (!playerTexture->loadFromFile("../Resources/player.png")) {
        std::cout << "ERROR LOADING TEXTURES\n";
    }
    playerTexture->setSmooth(true);

    myPlayerTexture = new sf::Texture;
    if (!myPlayerTexture->loadFromFile("../Resources/myPlayer.png")) {
        std::cout << "ERROR LOADING TEXTURES\n";
    }
    myPlayerTexture->setSmooth(true);

    bulletTexture = new sf::Texture;
    if (!bulletTexture->loadFromFile("../Resources/bullet.png")) {
        std::cout << "ERROR LOADING TEXTURES\n";
    }
    bulletTexture->setSmooth(true);

    myBulletTexture = new sf::Texture;
    if (!myBulletTexture->loadFromFile("../Resources/myBullet.png")) {
        std::cout << "ERROR LOADING TEXTURES\n";
    }
    myBulletTexture->setSmooth(true);
}

sf::Texture *Textures::getPlayerTexture() {
    return playerTexture;
}

sf::Texture *Textures::getMyPlayerTexture() {
    return myPlayerTexture;
}

sf::Texture *Textures::getBulletTexture() {
    return bulletTexture;
}

sf::Texture *Textures::getMyBulletTexture() {
    return myBulletTexture;
}

void Textures::unloadAll() {
    delete playerTexture;
    delete myPlayerTexture;
    delete bulletTexture;
    delete myBulletTexture;
}
