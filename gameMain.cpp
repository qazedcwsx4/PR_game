#include <iostream>
#include "Game/Game.h"

int main() {
    std::string command;

    //CLI for now
    //while (true){
    //std::cin >> command;
    //if (command=="test")
    //{
    Game game("127.0.0.1", 42000);
    game.launch();
    //}
    //}
    return 0;
}