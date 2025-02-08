#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Enemy.hpp"

class Player {
public:
    Player();
    ~Player();
    void attack(std::vector<Enemy>& enemies);
    void takeDamage(float damage);
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;
    const sf::Sprite& getSprite() const;
    float getSpeed() const;
    void gainExperience(float amount);
    void levelUp();
    bool isAlive = true;
private:
    std::shared_ptr<sf::Texture> texture;
    sf::Sprite sprite;
    float health;
    float attackDamage;
    float speed;
    int level;
    float experience;
    float attackRange;
};
#endif // PLAYER_HPP