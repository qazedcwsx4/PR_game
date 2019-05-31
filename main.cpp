#include <iostream>
#include "Game/Game.h"
int main() {
    std::string command;

    //CLI for now
    while (true){
        std::cin >> command;
        if (command=="test")
        {
            Game game;
            game.launch();
        }
    }
    return 0;
}