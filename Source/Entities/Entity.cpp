#include "Entities/Entity.hpp"
#include "Core/Constants.hpp"

#include <iostream>

// Default Entity Constructor
Entity::Entity() : 
entityName(EntityConstants::DEFAULT_NAME), 
healthPoints(EntityConstants::DEFAULT_HEALTH_POINTS),
protectionPoints(EntityConstants::DEFAULT_PROTECTION_POINTS),
strengthPoints(EntityConstants::DEFAULT_STRENGTH_POINTS),
bufferStrengthPoints(EntityConstants::DEFAULT_BUFFER_STRENGTH_POINTS),
speed(EntityConstants::DEFAULT_SPEED),
bufferSpeed(EntityConstants::DEFAULT_BUFFER_SPEED),
stamina(EntityConstants::DEFAULT_STAMINA),
position(EntityConstants::DEFAULT_POSITION),
velocity(EntityConstants::DEFAULT_VELOCITY),
width(EntityConstants::DEFAULT_WIDTH),
height(EntityConstants::DEFAULT_HEIGHT)
{
    isGrounded = false;

    shape.setSize(sf::Vector2f(EntityConstants::DEFAULT_WIDTH, EntityConstants::DEFAULT_HEIGHT));
    shape.setFillColor(sf::Color::White);
}

// Parameratized Entity Constructor
Entity::Entity(std::string entityName, 
    float healthPoints, 
    float protectionPoints, 
    float strengthPoints, 
    float bufferStrengthPoints,
    float speed,
    float bufferSpeed,
    float stamina,
    float width,
    float height,
    bool isGrounded,
    sf::Vector2f position,
    sf::Vector2f velocity
) :
entityName(entityName),
healthPoints(healthPoints),
protectionPoints(protectionPoints),
strengthPoints(strengthPoints),
bufferStrengthPoints(bufferStrengthPoints),
speed(speed),
bufferSpeed(bufferSpeed),
stamina(stamina),
position(position),
velocity(velocity),
width(width),
height(height),
isGrounded(isGrounded)
{
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::White);
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
    window.draw(shape);
}
// Update Entity
void Entity::update(float dt){
}

/*
* ========================
* Entity Setter Functions
* ========================
*/

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

void Entity::setPosition(float x, float y) {
    position = sf::Vector2f(x,y);
    shape.setPosition(position);
}

void Entity::setMap(Map* m_mapPtr) {this->m_mapPtr = m_mapPtr;}

/*
* ========================
* Entity Getter Functions
* ========================
*/

std::string Entity::getEntityName() const {
    return entityName;
}

float Entity::getHealthPoints() const {
    return healthPoints;
}

float Entity::getArmorPoints() const {
    return armorPoints;
}

float Entity::getStrengthPoints() const { return strengthPoints;}

float Entity::getBufferStrengthPoints() const { return bufferStrengthPoints; }

EntityClass Entity::getClass() const { return entityClass; }
EntityRank Entity::getRank() const { return entityRank; }

float Entity::getWidth() const {return width;}
float Entity::getHeight() const {return height;}
sf::Vector2f Entity::getPosition() const {return position;}
sf::Vector2f Entity::getVelocity() const {return velocity;}

sf::RectangleShape& Entity::getShape() {return shape;}
