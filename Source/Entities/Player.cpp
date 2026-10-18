#include "Entities/Player.hpp"
#include <cmath>

Player::Player() {
    entityName = "Unknown";
    healthPoints = 100.0f;
    protectionPoints = 0.0f;
    strengthPoints = 15.0f;
    speed = 200.0f;
    position = sf::Vector2f(400.0f, 300.0f);
}

Player::~Player() {}

void Player::update(float dt) {
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement.y -= 1.0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement.y += 1.0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement.x -= 1.0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement.x += 1.0;

    if (movement.x != 0.0 && movement.y != 0.0) {
        movement /= std::sqrt(2.0f);
    }

    // update position based on the speed and delta time
    position += movement * static_cast<float>(speed * dt);

    // update underlying SFML sprite position
    sprite.setPosition(position);
}

PlayerInventory& Player::getInventory() {
    return inventory;
}