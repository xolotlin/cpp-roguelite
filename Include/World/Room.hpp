#ifndef ROOM_HPP
#define ROOM_HPP

#pragma once

#include <SFML/Graphics.hpp>

#include "World/RoomType.hpp"
#include "World/Map.hpp"

class Room {
    private:
        int posX, posY;                         // Grid position 
        int roomTileWidth, roomTileHeight;      // Width and height in tiles
        
        RoomType type;
        bool isCleared;

    public:
        Room() {} // Default Constructor
        ~Room() {}

        sf::Vector2f getCenter(float tileSize) const {
            return sf::Vector2f((posX + roomTileWidth / 2.0f) * tileSize, (posY + roomTileHeight / 2.0f) * tileSize);
        }
};

#endif // ROOM_HPP