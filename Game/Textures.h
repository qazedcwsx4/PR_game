//
// Created by qaze on 01/06/2019.
//

#ifndef GAME_TEXTURES_H
#define GAME_TEXTURES_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Textures {
public:
    static sf::Texture *playerTexture;
    static sf::Texture *myPlayerTexture;
    static sf::Texture *bulletTexture;
    static sf::Texture *myBulletTexture;
public:
    static void loadAll();

    static sf::Texture *getPlayerTexture();

    static sf::Texture *getMyPlayerTexture();

    static sf::Texture *getBulletTexture();

    static sf::Texture *getMyBulletTexture();

};


#endif //GAME_TEXTURES_H
