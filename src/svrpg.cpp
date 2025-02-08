#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "SVRPG.hpp"

#include <iostream>
#include "Loot.hpp"

SVRPG::SVRPG(sf::Vector2u size) {
    window = sf::RenderWindow(sf::VideoMode(size), "SVRPG");
    window.setFramerateLimit(60);

    player = Player();
    enemies.push_back(Enemy(100, 10, sf::Vector2f(400.0f, 400.0f)));
    enemies.push_back(Enemy(100, 10, sf::Vector2f(200.0f, 300.0f)));
    enemies.push_back(Enemy(100, 10, sf::Vector2f(300.0f, 300.0f)));
    lootItems.push_back(Loot(500.0f, 500.0f));
    lootItems.push_back(Loot(600.0f, 600.0f));
    view = sf::View(player.getPosition(), sf::Vector2f(size));
}

SVRPG::~SVRPG() {

}

void SVRPG::run() {
    while(window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        handleEvents();
        update(deltaTime);
        render();
    }
}

void SVRPG::handleEvents() {
    window.handleEvents(
        [&](const sf::Event::Closed&) {
            window.close();
        },
        [&](const sf::Event::KeyPressed& keyPressed) {
            if (keyPressed.code == sf::Keyboard::Key::Escape) {
                window.close();
            }
            if (keyPressed.code == sf::Keyboard::Key::Space) {
                player.attack(enemies);
            }
        }
    );
}

void SVRPG::update(float deltaTime) {
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        movement.y -= player.getSpeed() * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        movement.y += player.getSpeed() * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        movement.x -= player.getSpeed() * deltaTime;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        movement.x += player.getSpeed() * deltaTime;
    
    for(auto& loot : lootItems) {
        loot.checkCollision(player);
    }

    player.setPosition(player.getPosition() + movement);
    view.setCenter(player.getPosition());
}

void SVRPG::render() {
    window.clear(sf::Color(0, 100, 0));
    if(player.isAlive)
        window.draw(player.getSprite());
    for(auto& enemy : enemies) {
        if(enemy.isAlive)
            window.draw(enemy.getSprite());
    }  
    for(auto& loot : lootItems) {
        if(!loot.isCollected())
            window.draw(loot.getSprite());
    }
    window.setView(view);
    window.display();
}