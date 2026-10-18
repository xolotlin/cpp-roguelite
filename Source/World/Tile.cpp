#include "World/Tile.hpp"
#include "Core/Constants.hpp"

// Default constructor
Tile::Tile() 
:   type(TileConstants::DEFAULT_TILE_TYPE), 
    solid(TileConstants::DEFAULT_TILE_IS_SOLID), 
    color(TileConstants::DEFAULT_TILE_COLOR), 
    position(TileConstants::DEFAULT_TILE_POSITION), 
    size(TileConstants::DEFAULT_TILE_SIZE) {}

// Parameterized
Tile::Tile(TileType type, sf::Vector2f position, float size) 
    : type(type), position(position), size(size) {
    // set properties automatically based on tile type
    switch(type) {
        case TileType::Ground:
            solid = true;
            color = sf::Color(50, 50, 60); 
            break;
        case TileType::Platform:
            solid = true;
            color = sf::Color(100, 70, 40);
            break;
        case TileType::Hazard:
            solid = false;
            color = sf::Color(200, 30, 30);
            break;
        case TileType::Empty:
        default:
            solid = false;
            color = sf::Color::Transparent;
            break;
    }
}

// Setter tile functions
void Tile::setType(TileType type) {
    this->type = type;

    if (type == TileType::Ground || type == TileType::Platform) {
        solid = true;
    } else {
        solid = false;
    }
}

void Tile::setPosition(float x, float y) {
    position = sf::Vector2f(x,y);
}

void Tile::setColor(sf::Color color) {
    this->color = color;
}

// Getter tile functions
TileType Tile::getType() const {return type;}
bool Tile::isSolid() const {return solid;}
sf::Color Tile::getColor() const {return color;}
sf::Vector2f Tile::getPosition() const {return position;}

// Rendering
void Tile::render(sf::RenderWindow& window) {
    // if its empty, don't waste time drawing anything
    if (type == TileType::Empty) return;

    sf::RectangleShape tileShape(sf::Vector2f(size, size));
    tileShape.setPosition(position);
    tileShape.setFillColor(color);

    // outline effect
    tileShape.setOutlineThickness(-1.f);
    // subtle dark border
    tileShape.setOutlineColor(sf::Color(20, 20, 20, 100));

    window.draw(tileShape);
    
}

