#include <iostream>
#include <fstream>
#include "SVRPG.hpp"

int main() {
    
    SVRPG game(sf::Vector2u(1280, 720));
    game.run();
    return 0;
}
