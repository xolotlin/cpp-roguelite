#include "Constants.hpp"

#include "Constants.hpp"

namespace ItemConstants {
    const std::vector<Item> DEFAULT_INVENTORY_STARTER_PACK = {}; 
    const unsigned int DEFAULT_INVENTORY_SPACE = 10;
    const unsigned int DEFAULT_MAX_INVENTORY_SPACE = 30;

    const std::string ITEM_NAME_EMPTY = "Empty";
    const std::string ITEM_DESCRIPTION_EMPTY = "";
    const float ITEM_VALUE_EMPTY = 0.0f;
    const float ITEM_WEIGHT_EMPTY = 0.0f;
}

namespace MapConstants {
    const float MAP_TILE_SIZE = 32.f;
};

namespace TileConstants {
    const float DEFAULT_TILE_SIZE = 32.f;
    const sf::Color DEFAULT_TILE_COLOR = sf::Color::Transparent;
    const bool DEFAULT_TILE_IS_SOLID = false;
    const sf::Vector2f DEFAULT_TILE_POSITION = {0.f, 0.f};
};