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

    float targetXVelocity = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        targetXVelocity = -speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        targetXVelocity = speed;
    }

    // Interpolation current velocity toward velocity
    float smoothFactor = 10.0f;
    velocity.x += (targetXVelocity - velocity.x) * smoothFactor * dt;

    velocity.y += gravity * dt; // Apply gravity every frame

    // Handle jumping
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && isGrounded) {
        velocity.y = jumpForce;
        isGrounded = false;
    }

     position.x += velocity.x * dt;

    // Dynamic tile mapping bounds recalculation
    int tileTop = static_cast<int>(position.y / tileSize);
    int tileBottom = static_cast<int>((position.y + height - 0.1f) / tileSize); // Sub-pixel padding prevents corner-snagging

    if (velocity.x > 0.0f) 
    {
        int tileRight = static_cast<int>((position.x + width) / tileSize);
        for (int y = tileTop; y <= tileBottom; ++y) {
            if (m_mapPtr->isSolid(tileRight, y)) {
                position.x = tileRight * tileSize - width;
                velocity.x = 0.0f; // Kill velocity on impact with a wall
                break;
            }
        }
    } 
    else if (velocity.x < 0.0f) 
    {
        int tileLeft = static_cast<int>(position.x / tileSize);
        for (int y = tileTop; y <= tileBottom; ++y) {
            if (m_mapPtr->isSolid(tileLeft, y)) {
                position.x = (tileLeft + 1) * tileSize;
                velocity.x = 0.0f; // Kill velocity on impact with a wall
                break;
            }
        }
    }

    //Vertical Handle
    isGrounded = false;
    position.y += velocity.y * dt;

    // Dynamic tile mapping bounds recalculation after horizontal shift
    int tileLeft = static_cast<int>(position.x / tileSize);
    int tileRight = static_cast<int>((position.x + width - 0.1f) / tileSize); // Sub-pixel padding prevents corner-snagging

    if (velocity.y > 0.0f) {
        int tileBottomPass = static_cast<int>((position.y + height) / tileSize);
        for (int x = tileLeft; x <= tileRight; ++x) {
            if (m_mapPtr->isSolid(x, tileBottomPass)) {
                position.y = tileBottomPass * tileSize - height;
                velocity.y = 0.0f;
                isGrounded = true;
                break;
            }
        }
    } else if (velocity.y < 0.0f) {
        int tileTopPass = static_cast<int>(position.y / tileSize);
        for (int x = tileLeft; x <= tileRight; ++x) {
            if (m_mapPtr->isSolid(x, tileTopPass)) {
                position.y = (tileTopPass + 1) * tileSize;
                velocity.y = 0.0f;
                break;
            }
        }
    }

    // Sync graphics object with new clean coordinates
    shape.setPosition(position);
}

void Player::setMap(Map* m_mapPtr) {this->m_mapPtr = m_mapPtr;}

PlayerInventory& Player::getInventory() {
    return inventory;
}