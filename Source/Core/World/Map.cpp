#include "Map.hpp"
#include "Constants.hpp"
#include <iostream>

// Default constructor
Map::Map()
    : width(MapConstants::DEFAULT_MAP_WIDTH), 
    height(MapConstants::DEFAULT_MAP_HEIGHT), 
    tileSize(MapConstants::MAP_TILE_SIZE) {
        // initialize default 2d grid dimensions
        grid.resize(MapConstants::DEFAULT_MAP_HEIGHT, std::vector<Tile>(MapConstants::DEFAULT_MAP_WIDTH));

        generate();
    }

// paramaratized constructor 
Map::Map(int width, int height, float size)
    : width(width), height(height), tileSize(size) {
    // initialize 2D grid dimensions
    grid.resize(height, std::vector<Tile>(width));

    // generate map
    generate();
}
Map::~Map() {}

void Map::render(sf::RenderWindow& window) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x].render(window);
            std::cout << "Rendered: " << y << " " << x << std::endl;
        } 
    }
}

bool Map::isSolid(int gridX, int gridY) const {
    // keep players inside map by treating out of bounds cords as solid
    if (gridX < 0 || gridX >= width || gridY < 0 || gridY >= height) {
        return 0;
    }
    return grid[gridY][gridX].isSolid();
}

void Map::generate() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            sf::Vector2f pos(x * tileSize, y * tileSize);
            // create solid outer boundaries (walls left/right, floor at bottom)
            if (x == 0 || x == width - 1 || y == height - 1) {
                grid[y][x] = Tile(TileType::Ground, pos, tileSize);
            } else if (y % 4 == 0 && x > 2 && x < width - 3 && (x+y) % 3 == 0) {
                grid[y][x] = Tile(TileType::Platform, pos, tileSize);
            } else {
                grid[y][x] = Tile(TileType::Empty, pos, tileSize);
            }
        }
    }
}

// Setter map functions

void Map::setMapWidth(int width) {
    if(width > 0) 
        this->width = width;
    else
        std::cerr << "[Error]: Map width must be positive.\n";
}

void Map::setMapHeight(int height) {
    if (height > 0) 
        this->height = height;
    else
        std::cerr << "[Error]: Map height must be positive.\n";
}

// Getter map functions

int Map::getWidth() const { return width; }

int Map::getHeight() const { return height; }

