#include "Player.hpp"
#include "Enemy.hpp"

#include <memory>
#include <iostream>

Enemy::Enemy(float health, float attackDamage, sf::Vector2f position) : health(health), attackDamage(attackDamage) {
    texture = std::make_shared<sf::Texture>();
    if(!texture->loadFromFile("assets/enemy.png"))  {
        std::cerr << "Failed to load enemy texture!" << std::endl;
        exit(-1);
    }

    sprite = sf::Sprite(*texture); 
    sprite.setPosition(position);
};

Enemy::~Enemy() {

}

const sf::Sprite& Enemy::getSprite() const {
    return sprite;
}

void Enemy::setPosition(const sf::Vector2f& position) {
    sprite.setPosition(position);
}
sf::Vector2f Enemy::getPosition() const {
    return sprite.getPosition();
}

float Enemy::getHealth() {
    return health;
}

void Enemy::takeDamage(float damage) {
    if(isAlive)
        health -= damage;
    
    if(health <= 0.0f)
        isAlive = false;
}
