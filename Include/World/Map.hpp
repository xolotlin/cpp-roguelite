#ifndef MAP_HPP
#define MAP_HPP

#pragma once
#include <SFML/Graphics.hpp>

#include "World/Tile.hpp"
#include "World/Room.hpp"
#include "World/Biome.hpp"

#include <vector>

class Room;

class Map {
    private:
        int width;
        int height;
        float tileSize; 

        Biome currentBiome; // theme of map
        sf::Vector2f spawnPosition;
        std::vector<Room> rooms; // Stores all generated rooms
        std::vector<Biome> biomes;
        sf::VertexArray mapVertices;

        std::vector<std::vector<Tile>> grid; // grid data
    public:
        Map(); // Default constructor
        Map(int mapWidth, int mapHeight, float size); // parameritized constructor
        ~Map();

        void render(sf::RenderWindow& window);
        void generate(); // Generate procedural world

        // Setter map functions
        void setMapWidth(int width);
        void setMapHeight(int height);
        
        bool isSolid(int gridX, int gridY) const;
        // Getter map functions
        int getWidth() const { return width; }
        int getHeight() const { return height; }
        sf::Vector2f getSpawnPosition() const { return spawnPosition; }
        const std::vector<Room>& getRooms() const { return rooms; }
        const std::vector<Biome>& getBiomes() const { return biomes; }
        Biome getBiome() const { return currentBiome; }
};
#endif // MAP_HPP