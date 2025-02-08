#include "Player.hpp"
#include "Enemy.hpp"
#include <iostream>

#include <memory>
#include <math.h>

Player::Player() : health(20.0f), attackDamage(10.0f), speed(100.0f), attackRange(25.0f), experience(0.0f), level(1) {
    texture = std::make_shared<sf::Texture>();
    if(!texture->loadFromFile("assets/player.png"))  {
        std::cerr << "Failed to load player texture!" << std::endl;
        exit(-1);
    }
    sprite = sf::Sprite(*texture); 
    sprite.setPosition(sf::Vector2f(400.0f, 300.0f));
};

Player::~Player() {

}

const sf::Sprite& Player::getSprite() const{
    return sprite;
}

float Player::getSpeed() const {
    return speed;
}

void Player::setPosition(const sf::Vector2f& position) {
    sprite.setPosition(position);
}

sf::Vector2f Player::getPosition() const {
    return sprite.getPosition();
}

void Player::attack(std::vector<Enemy>& enemies) {
    for (auto& enemy : enemies) {
        if(!enemy.isAlive) 
            continue;
        float distance = sqrt(pow(getPosition().x - enemy.getPosition().x, 2) + pow(getPosition().y - enemy.getPosition().y, 2));
        if (distance < attackRange) { 
            enemy.takeDamage(attackDamage); 
            if (!enemy.isAlive) {
                gainExperience(50.0f);
            }
        }
    }
    
}

void Player::takeDamage(float damage) {
    if(isAlive)
        health -= damage;
    
    if (health <= 0.0f) 
        isAlive = false;
}

void Player::gainExperience(float amount) {
    experience += amount;
    if (experience >= 100.0f) {
        levelUp();
    }
}

void Player::levelUp() {
    int levelUps = experience / 100.0f;
    experience -= levelUps * 100.0f;
    level+= levelUps;
    health += 10.0f;
    attackDamage += 5.0f;
    std::cout << "Leveled up! New level: " << level << std::endl;
}