#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "SVRPG.hpp"

#include <iostream>

SVRPG::SVRPG(sf::Vector2u size) {
    window = sf::RenderWindow(sf::VideoMode(size), "SVRPG");
    window.setFramerateLimit(60);

    player = Player();
    enemies.push_back(Enemy(100, 10, sf::Vector2f(400.0f, 400.0f)));
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

    player.setPosition(player.getPosition() + movement);
    view.setCenter(player.getPosition());
}

void SVRPG::render() {
    window.clear();
    window.draw(*player.getSprite());
    for(auto& enemy : enemies) {
        window.draw(*enemy.getSprite());
    }  
    window.setView(view);
    window.display();
}