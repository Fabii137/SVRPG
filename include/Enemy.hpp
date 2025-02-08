#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>

class Enemy {
public:
    Enemy(float health, float attackDamage, sf::Vector2f position);
    ~Enemy();
    float getHealth();
    void takeDamage(float damage);
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;
    sf::Sprite* getSprite();
    bool isAlive;
private:
    sf::Texture texture;
    sf::Sprite* sprite;
    float health;
    float attackDamage;
    float speed;
};

#endif // ENEMY_HPP