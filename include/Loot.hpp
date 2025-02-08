#ifndef LOOT_HPP
#define LOOT_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include "Player.hpp"

class Loot {
public:
    Loot(float x, float y);
    const sf::Sprite& getSprite() const;
    bool checkCollision(Player& player);
    bool isCollected() const;

private:
    sf::Sprite sprite;
    std::shared_ptr<sf::Texture> texture;
    bool collected;
};

#endif // LOOT_HPP




