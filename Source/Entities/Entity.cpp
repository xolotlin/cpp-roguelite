#include "Entity.hpp"
#include <iostream>

Entity::Entity() {
    entityName = "Unknown";
    healthPoints = 100.0f;
    protectionPoints = 0.0f;
    strengthPoints = 10.0f;
    bufferStrengthPoints = 0.0f;
    speed = 200.0f;
    bufferSpeed = 0.0f;
    stamina = 100.0f;
    position = sf::Vector2f(0.0f, 0.0f);
}

Entity::~Entity() {}

// Load Assets
void Entity::loadAssets() {
    if (!texture.loadFromFile("Assets/test.png")) {
        std::cerr << "Error: Couldn't load entity texture" << std::endl;
    }
    sprite.setTexture(texture);
}
// Render Entity
void Entity::render(sf::RenderWindow& window) {
    window.draw(sprite);
}
// Update Entity
void Entity::update(float dt){

}
// Entity setter functions

void Entity::setHealthPoints(float healthPoints) {
    this->healthPoints = healthPoints;
}

void Entity::setArmorPoints(float armorPoints) {
    this->armorPoints = armorPoints;
}

void Entity::setStrengthPoints(float strengthPoints) {
    this->strengthPoints = strengthPoints;
}

void Entity::setBufferStrengthPoints(float bufferStrengthPoints) {
    this->bufferStrengthPoints = bufferStrengthPoints;
}

// Entity getter functions
std::string Entity::getEntityName() const {
    return entityName;
}

float Entity::getHealthPoints() const {
    return healthPoints;
}

float Entity::getArmorPoints() const {
    return armorPoints;
}

float Entity::getStrengthPoints() const {
    return strengthPoints;
}

float Entity::getBufferStrengthPoints() const {
    return bufferStrengthPoints;
}

sf::Vector2f Entity::getPosition() const{
    return position;
}

EntityClass Entity::getClass() const {
    return entityClass;
}

EntityRank Entity::getRank() const {
    return entityRank;
}
