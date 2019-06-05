#include <iostream>
#include "Server/Server.h"

int main() {
    Server server("127.0.0.1", 42000);
    server.loop();
    return 0;
}