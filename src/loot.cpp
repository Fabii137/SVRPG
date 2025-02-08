#include "Loot.hpp"
#include "Player.hpp"

Loot::Loot(float x, float y) : collected(false) {
    texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile("assets/loot.png")) {
        std::cerr << "Failed to load loot texture!" << std::endl;
        exit(-1);
    }
    sprite = sf::Sprite(*texture);
    sprite.setPosition(sf::Vector2f(x, y));
}

bool Loot::checkCollision(Player& player) {
    if (collected) {
        return false;
    }
    sf::FloatRect lootBounds = sprite.getGlobalBounds();
    sf::FloatRect playerBounds = player.getSprite().getGlobalBounds();

    std::optional<sf::FloatRect> intersection = lootBounds.findIntersection(playerBounds);

    if (intersection.has_value()) {
        std::cout << "collected" << std::endl;
        collected = true;
        return true;
    }

    return false;
}

const sf::Sprite& Loot::getSprite() const {
    return sprite;
}

bool Loot::isCollected() const {
    return collected;
}