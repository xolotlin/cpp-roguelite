#ifndef TILE_HPP
#define TILE_HPP

#pragma once
#include <SFML/Graphics.hpp>

#include "TileType.hpp"

class Tile {
    private:
        TileType type;
        bool solid;
        sf::Color color;
        sf::Vector2f position;
        float size;

    public:
        Tile();
        Tile(TileType type, sf::Vector2f position, float size);

        void render(sf::RenderWindow& window);

        // Setter tile functions
        void setType(TileType type);
        void setPosition(float x, float y);
        void setColor(sf::Color color);

        // Getter tile functions
        TileType getType() const;
        bool isSolid() const;
        sf::Color getColor() const;
        sf::Vector2f getPosition() const;
};

#endif