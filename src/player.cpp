#include "Player.hpp"
#include "Enemy.hpp"
#include <iostream>

Player::Player() : health(20.0f), attackDamage(10.0f), speed(100.0f) {
    if(!texture.loadFromFile("assets/player.png"))  {
        std::cerr << "Failed to load player texture!" << std::endl;
        exit(-1);
    }
    sprite = new sf::Sprite(texture); 
    sprite->setPosition(sf::Vector2f(400.0f, 300.0f));
};

Player::~Player() {
    if(sprite)
        delete sprite;
}

sf::Sprite* Player::getSprite() const{
    return sprite;
}

float Player::getSpeed() const {
    return speed;
}

void Player::setPosition(const sf::Vector2f& position) {
    sprite->setPosition(position);
}

sf::Vector2f Player::getPosition() const {
    return sprite->getPosition();
}

void Player::attack(Enemy& target) {
    target.takeDamage(attackDamage);
}

void Player::takeDamage(float damage) {
    if(isAlive)
        health -= damage;
    
    if (health <= 0.0f) 
        isAlive = false;
    
}