#include "World/Map.hpp"
#include "Core/Constants.hpp"
#include <iostream>
#include <random>
#include <algorithm>

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
        }
    }
}

bool Map::isSolid(int gridX, int gridY) const {
    // keep players inside map by treating out of bounds cords as solid
    if (gridX < 0 || gridX >= width || gridY < 0 || gridY >= height) {
        return true;
    }
    return grid[gridY][gridX].isSolid();
}

 void Map::generate() {
    // 1. Fill the entire map with solid ground
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = Tile(TileType::Ground, sf::Vector2f(x * tileSize, y * tileSize), tileSize);
        }
    }

    struct Room {
        int x, y, w, h;
        int centerX() const { return x + w / 2; }
        int centerY() const { return y + h / 2; }
    };

    std::vector<Room> rooms;
    std::random_device rd;
    std::mt19937 gen(rd());

    // Ensure map is large enough, or scale down room size bounds safely
    int minSize = 5;
    int maxSize = std::min(12, std::min(width - 4, height - 4));
    if (maxSize < minSize) maxSize = minSize;

    std::uniform_int_distribution<int> roomCountDist(4, 7);
    std::uniform_int_distribution<int> sizeDist(minSize, maxSize);

    int numRooms = roomCountDist(gen);

    // 2. Carve out random rooms
    for (int i = 0; i < numRooms; ++i) {
        Room newRoom;
        newRoom.w = sizeDist(gen);
        newRoom.h = sizeDist(gen);

        if (i==0) {
            newRoom.x = 2;
            newRoom.y = 2;
        } else {
            // Safe coordinate distributions based on actual map dimensions
            std::uniform_int_distribution<int> posDistX(1, width - newRoom.w - 1);
            std::uniform_int_distribution<int> posDistY(1, height - newRoom.h - 1);

            newRoom.x = posDistX(gen);
            newRoom.y = posDistY(gen);
        }

        // Carve room space to Empty (air)
        for (int y = newRoom.y; y < newRoom.y + newRoom.h; ++y) {
            for (int x = newRoom.x; x < newRoom.x + newRoom.w; ++x) {
                grid[y][x] = Tile(TileType::Empty, sf::Vector2f(x * tileSize, y * tileSize), tileSize);
            }
        }

        // If this room 0, set the player's spawn position to the middle of this room
        if (i == 0) {
            float spawnPixelX = (newRoom.x + newRoom.w / 2.0f) * tileSize;
            float spawnPixelY = (newRoom.y + newRoom.h / 2.0f) * tileSize;
            spawnPosition = sf::Vector2f(spawnPixelX, spawnPixelY);
        }

        // Add a platform inside the room
        if (newRoom.h > 4) {
            int platformY = newRoom.y + newRoom.h / 2;
            for (int px = newRoom.x + 1; px < newRoom.x + newRoom.w - 1; ++px) {
                if (px % 3 == 0) {
                    grid[platformY][px] = Tile(TileType::Platform, sf::Vector2f(px * tileSize, platformY * tileSize), tileSize);
                }
            }
        }

        rooms.push_back(newRoom);
    }

    // 3. Connect rooms with corridors
    for (size_t i = 0; i < rooms.size() - 1; ++i) {
        int x1 = rooms[i].centerX();
        int y1 = rooms[i].centerY();
        int x2 = rooms[i + 1].centerX();
        int y2 = rooms[i + 1].centerY();

        // Horizontal tunnel
        for (int x = std::min(x1, x2); x <= std::max(x1, x2); ++x) {
            grid[y1][x] = Tile(TileType::Empty, sf::Vector2f(x * tileSize, y1 * tileSize), tileSize);
            if (y1 + 1 < height) {
                grid[y1 + 1][x] = Tile(TileType::Ground, sf::Vector2f(x * tileSize, (y1 + 1) * tileSize), tileSize);
            }
        }

        // Vertical tunnel
        for (int y = std::min(y1, y2); y <= std::max(y1, y2); ++y) {
            grid[y][x2] = Tile(TileType::Empty, sf::Vector2f(x2 * tileSize, y * tileSize), tileSize);
        }
    }
}

// Setter map functions

void Map::setMapWidth(int width) {
    if(width > 0) this->width = width;
    else std::cerr << "[Error]: Map width must be positive.\n";
}

void Map::setMapHeight(int height) {
    if (height > 0) this->height = height;
    else std::cerr << "[Error]: Map height must be positive.\n";
}

// Getter map functions

int Map::getWidth() const { return width; }

int Map::getHeight() const { return height; }

