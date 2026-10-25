#include "Core/Constants.hpp"

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
    const float MAP_TILE_SIZE = 32.0f;
};

namespace TileConstants {
    const float DEFAULT_TILE_SIZE = 32.0f;
    const sf::Color DEFAULT_TILE_COLOR = sf::Color::Transparent;
    const bool DEFAULT_TILE_IS_SOLID = false;
    const sf::Vector2f DEFAULT_TILE_POSITION = {0.0f, 0.0f};
};

namespace EntityConstants {
    const float DEFAULT_WIDTH = 32.0f;
    const float DEFAULT_HEIGHT = 32.0f;
    const float DEFAULT_HEALTH_POINTS = 100.0f;
    const float DEFAULT_PROTECTION_POINTS = 0.0f;
    const float DEFAULT_STRENGTH_POINTS = 10.0f;
    const float DEFAULT_BUFFER_STRENGTH_POINTS = 0.0f;
    const float DEFAULT_SPEED = 200.0f;
    const float DEFAULT_BUFFER_SPEED = 0.0f;
    const float DEFAULT_STAMINA = 100.0f;
};

namespace PlayerConstants {
    extern const float DEFAULT_WIDTH = 32.0f;
    extern const float DEFAULT_HEIGHT = 32.0f;
    extern const float DEFAULT_HEALTH_POINTS = 100.0f;
    extern const float DEFAULT_PROTECTION_POINTS = 0.0f;
    extern const float DEFAULT_STRENGTH_POINTS = 10.0f;
    extern const float DEFAULT_BUFFER_STRENGTH_POINTS = 0.0f;
    extern const float DEFAULT_SPEED = 200.0f;
    extern const float DEFAULT_BUFFER_SPEED = 0.0f;
    extern const float DEFAULT_STAMINA = 100.0f;
};