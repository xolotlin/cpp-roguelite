#include "Entities/Player.hpp"
#include "World/Map.hpp"
#include "Core/Constants.hpp"
#include <cmath>

// Default Constructor
Player::Player() 
: Entity(
    PlayerConstants::DEFAULT_NAME,                                          // Default Player Name
    PlayerConstants::DEFAULT_HEALTH_POINTS,                                 // Default health points
    PlayerConstants::DEFAULT_PROTECTION_POINTS,                             // Default protection points
    PlayerConstants::DEFAULT_STRENGTH_POINTS,                               // Default strength points
    PlayerConstants::DEFAULT_BUFFER_STRENGTH_POINTS,                        // Default buffer strength points
    PlayerConstants::DEFAULT_SPEED,                                         // speed
    PlayerConstants::DEFAULT_BUFFER_SPEED,                                  // buffer speed
    PlayerConstants::DEFAULT_STAMINA,                                       // stamina
    EntityConstants::DEFAULT_WIDTH,                                         // width
    EntityConstants::DEFAULT_HEIGHT,                                        // height
    false,                                                                  // isGrounded
    EntityConstants::DEFAULT_POSITION,                                      // position
    EntityConstants::DEFAULT_VELOCITY                                       // velocity
) // Call default Entity Constructor automatically
{
    shape.setSize(sf::Vector2f(EntityConstants::DEFAULT_WIDTH, EntityConstants::DEFAULT_HEIGHT));
    shape.setFillColor(sf::Color(70,130,180));
    shape.setPosition(EntityConstants::DEFAULT_POSITION);
}

// Parameterized constructor
Player::Player(std::string entityName, float healthPoints, float protectionPoints, float strengthPoints, float speed, sf::Vector2f position) :
Entity(
    entityName, 
    healthPoints, 
    protectionPoints, 
    strengthPoints,                                                         // Strength points
    0.0f,                                                                   // Buffer strength points
    speed,                                                                  // speed
    0.0f,                                                                   // Buffer speed
    100.0f,                                                                 // Stamina
    EntityConstants::DEFAULT_WIDTH,
    EntityConstants::DEFAULT_HEIGHT,
    false,                                                                  // isGrounded
    position,
    sf::Vector2f(0.0f, 0.0f)                                                 
) 
{
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color(70,130,180));
    shape.setPosition(position);
}

Player::~Player() {}

// Update player motion
void Player::update(float dt) {
    if (!m_mapPtr) return;

    const float gravity = 900.0f;
    const float jumpForce = -420.0f;
    const float tileSize = MapConstants::MAP_TILE_SIZE;

    velocity.x = 0.0f; // Static, no motion

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x = -speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x = speed;
    }

    velocity.y += gravity * dt; // Apply gravity every frame

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && isGrounded) {
        velocity.y = jumpForce;
        isGrounded = false;
    }

    // Horizontal Collision & movement
    position.x += velocity.x * dt;
    shape.setPosition(position);

    float left = position.x;
    float right = position.x + width;
    float top = position.y;
    float bottom = position.y + height;

    int tileLeft = static_cast<int>(left / tileSize);
    int tileRight = static_cast<int>(right / tileSize);
    int tileTop = static_cast<int>(top / tileSize);
    int tileBottom = static_cast<int>(bottom / tileSize);

    // Check if velocity (with respect to x) is positve
    if (velocity.x > 0.0f) 
    {
        for (int y = tileTop; y <= tileBottom; ++y) {
            if (m_mapPtr->isSolid(tileRight, y)) {
                position.x = tileRight * tileSize - width;
                velocity.x = 0.0f;
                break;
            }
        }
    } 
    // Check if velocity (with respect to x) is negative
    else if (velocity.x < 0.0f) 
    {
        for (int y = tileTop; y <= tileBottom; ++y) {
            if (m_mapPtr->isSolid(tileLeft, y)) {
                position.x = (tileLeft + 1) * tileSize;
                velocity.x = 0.0f;
                break;
            }
        }
    }

    // Veritcal collision & movement
    isGrounded = false;
    position.y += velocity.y * dt;
    shape.setPosition(position);

    left = position.x;
    right = position.x + width;
    top = position.y;
    bottom = position.y + height;

    tileLeft = static_cast<int>(left / tileSize);
    tileRight = static_cast<int>(right / tileSize);
    tileTop = static_cast<int>(top / tileSize);
    tileBottom = static_cast<int>(bottom / tileSize);

    if (velocity.y > 0.0f) {
        for (int x = tileLeft; x <= tileRight; ++x) {
            if (m_mapPtr->isSolid(x, tileBottom)) {
                position.y = tileBottom * tileSize - height;
                velocity.y = 0.0f;
                isGrounded = true;
                break;
            }
        }
    } else if (velocity.y < 0.0f) {
        for (int x = tileLeft; x <= tileRight; ++x) {
            if (m_mapPtr->isSolid(x, tileTop)) {
                position.y = (tileTop + 1) * tileSize;
                velocity.y = 0.0f;
                break;
            }
        }
    }

    // update underlying SFML sprite position
    shape.setPosition(position);
}

void Player::setMap(Map* m_mapPtr) {this->m_mapPtr = m_mapPtr;}

PlayerInventory& Player::getInventory() {
    return inventory;
}