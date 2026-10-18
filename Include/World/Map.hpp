#ifndef MAP_HPP
#define MAP_HPP

#pragma once
#include "SFML/Graphics.hpp"

#include "World/Tile.hpp"

#include <vector>

class Map {
    private:
        int width;
        int height;
        float tileSize; 

        std::vector<std::vector<Tile>> grid;
    public:
        Map();
        Map(int mapWidth, int mapHeight, float size);
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

        
        
        
};
#endif