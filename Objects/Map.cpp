//
// Created by qaze on 31/05/2019.
//

#include "Map.h"

Map::Map(sf::RenderWindow &renderWindow) : renderWindow(renderWindow) {
    float wid = 1280;
    float hei = 720;
    walls.emplace_back(renderWindow, 20, 20, wid - 20, 20);
    walls.emplace_back(renderWindow, 20, 20, 20, hei - 20);
    walls.emplace_back(renderWindow, 20, hei - 20, wid - 20, hei - 20);
    walls.emplace_back(renderWindow, wid - 20, 20, wid - 20, hei - 20);

    walls.emplace_back(renderWindow, wid / 2 - 200, hei / 2, wid / 2, hei / 2 + 200);
    walls.emplace_back(renderWindow, wid / 2 - 200, hei / 2, wid / 2, hei / 2 - 200);
    walls.emplace_back(renderWindow, wid / 2, hei / 2 + 200, wid / 2 + 200, hei / 2);
    walls.emplace_back(renderWindow, wid / 2, hei / 2 - 200, wid / 2 + 200, hei / 2);
}

void Map::render() {
    for (auto &wall : walls) {
        wall.render();
    }
}

std::vector<Wall> &Map::getWalls() {
    return walls;
}
