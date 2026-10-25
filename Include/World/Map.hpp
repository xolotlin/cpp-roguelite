#ifndef MAP_HPP
#define MAP_HPP

#pragma once
#include <SFML/Graphics.hpp>

#include "World/Tile.hpp"

#include <vector>

class Map {
    private:
        int width;
        int height;
        float tileSize; 

        sf::Vector2f spawnPosition;

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
        int getWidth() const;
        int getHeight() const;
        sf::Vector2f getSpawnPosition() const { return spawnPosition; }

        sf::VertexArray mapVerticies;
        void buildVertexArray();
        
        
};
#endif // MAP_HPP