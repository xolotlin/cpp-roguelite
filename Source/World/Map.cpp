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
    window.draw(mapVertices);
}

bool Map::isSolid(int gridX, int gridY) const {
    // keep players inside map by treating out of bounds cords as solid
    if (gridX < 0 || gridX >= width || gridY < 0 || gridY >= height) {
        return true;
    }
    return grid[gridY][gridX].isSolid();
}

 void Map::generate() {
    // Clear out old room vectors if regenerating maps
    rooms.clear();

    biomes = {
        BiomeRegistry::STONE_DUNGEON,
        BiomeRegistry::DESERT_DUNGEON,
        BiomeRegistry::FOREST_DUNGEON,
        BiomeRegistry::ICE_DUNGEON,
        BiomeRegistry::MAGMA_DUNGEON,

    };

    // 1. Fill the entire map with solid ground
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = Tile(TileType::Ground, sf::Vector2f(x * tileSize, y * tileSize), tileSize);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    // Ensure map is large enough, or scale down room size bounds safely
    int minSize = 5;
    int maxSize = std::min(12, std::min(width - 4, height - 4));
    if (maxSize < minSize) maxSize = minSize;

    std::uniform_int_distribution<int> roomCountDist(4, 7);
    std::uniform_int_distribution<int> sizeDist(minSize, maxSize);
    std::uniform_int_distribution<int> biomeDist(0, biomes.size() - 1);

    currentBiome = biomes[biomeDist(gen)];

    std::cout << "Generating Layout Theme: " << currentBiome.name << std::endl;

    int numRooms = roomCountDist(gen);

    // Carve out random rooms
    for (int i = 0; i < numRooms; ++i) {
        Room newRoom;
        newRoom.roomTileWidth = sizeDist(gen);
        newRoom.roomTileHeight = sizeDist(gen);

        if (i==0) {
            newRoom.posX = 2;
            newRoom.posY = 2;
        } else {
            // Safe coordinate distributions based on actual map dimensions
            std::uniform_int_distribution<int> posDistX(1, width - newRoom.roomTileWidth - 1);
            std::uniform_int_distribution<int> posDistY(1, height - newRoom.roomTileHeight - 1);

            newRoom.posX = posDistX(gen);
            newRoom.posY = posDistY(gen);
        }

        // Carve room space to Empty (air)
        for (int y = newRoom.posY; y < newRoom.posY + newRoom.roomTileHeight; ++y) {
            for (int x = newRoom.posX; x < newRoom.posX + newRoom.roomTileWidth; ++x) {
                grid[y][x] = Tile(TileType::Empty, sf::Vector2f(x * tileSize, y * tileSize), tileSize);
            }
        }

        // If this room 0, set the player's spawn position to the middle of this room
        if (i == 0) {
            float spawnPixelX = (newRoom.posX + newRoom.roomTileWidth / 2.0f) * tileSize;
            float spawnPixelY = (newRoom.posY + newRoom.roomTileHeight / 2.0f) * tileSize;
            spawnPosition = sf::Vector2f(spawnPixelX, spawnPixelY);
        }

        // Add a platform inside the room
        if (newRoom.roomTileHeight > 4) {
            int platformY = newRoom.posY + newRoom.roomTileHeight / 2;
            for (int px = newRoom.posX + 1; px < newRoom.posX + newRoom.roomTileWidth - 1; ++px) {
                if (px % 3 == 0) {
                    grid[platformY][px] = Tile(TileType::Platform, sf::Vector2f(px * tileSize, platformY * tileSize), tileSize);
                }
            }
        }
        rooms.push_back(newRoom);
    }

    // Connect rooms with corridors
    for (size_t i = 0; i < rooms.size() - 1; ++i) {
        int x1 = rooms[i].posX + rooms[i].roomTileWidth / 2;
        int y1 = rooms[i].posY + rooms[i].roomTileHeight / 2;
        int x2 = rooms[i + 1].posX + rooms[i + 1].roomTileWidth / 2;
        int y2 = rooms[i + 1].posY + rooms[i + 1].roomTileHeight / 2;


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

    // batch generated grid info into the gpu vertex array
    mapVertices.setPrimitiveType(sf::Quads);
    mapVertices.resize(width * height * 4);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int tileIndex = (x + y * width) * 4;
            sf::Vertex* quad = &mapVertices[tileIndex];

            // Set coordinates for the 4 corners of the quad
            quad[0].position = sf::Vector2f(x * tileSize, y * tileSize);
            quad[1].position = sf::Vector2f((x + 1) * tileSize, y * tileSize);
            quad[2].position = sf::Vector2f((x + 1) * tileSize, (y + 1) * tileSize);
            quad[3].position = sf::Vector2f(x * tileSize, (y + 1) * tileSize);

            // Dynamically assign theme colors from our current Biome properties
            sf::Color tileColor;
            if (grid[y][x].isSolid()) {
                tileColor = currentBiome.groundColor; // Solid wall color
            } else if (grid[y][x].getType() == TileType::Platform) {
                tileColor = currentBiome.platformColor; // platform wall color
            } else {
                tileColor = currentBiome.emptySpaceColor;    
            }

            // Bind the chosen biome to all vertex coordinates
            quad[0].color = tileColor;
            quad[1].color = tileColor;
            quad[2].color = tileColor;
            quad[3].color = tileColor;
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