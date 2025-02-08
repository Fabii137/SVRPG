#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Enemy.hpp"

class Player {
public:
    Player();
    ~Player();
    void attack(Enemy& target);
    void takeDamage(float damage);
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;
    sf::Sprite* getSprite() const;
    float getSpeed() const;
    bool isAlive;
private:
    sf::Texture texture;
    sf::Sprite* sprite;
    float health;
    float attackDamage;
    float speed;
};
#endif // PLAYER_HPP