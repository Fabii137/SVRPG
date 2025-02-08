#ifndef SVRPG_HPP
#define SVRPG_HPP

#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Loot.hpp"

class SVRPG {
public:
    SVRPG(sf::Vector2u size);
    ~SVRPG();

    void run(); 

private:
    void handleEvents();
    void update(float deltaTime);
    void render();

    sf::RenderWindow window;
    sf::View view;
    Player player;
    std::vector<Enemy> enemies;
    std::vector<Loot> lootItems;
    sf::Clock clock;
};

#endif  // SVRPG_HPP
