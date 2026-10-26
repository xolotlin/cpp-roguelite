#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include "SFML/Graphics.hpp"

#include <vector>
#include <string>

#include "Entities/Items/ItemType.hpp"
#include "Entities/Items/ItemRarity.hpp"
#include "Entities/Items/ItemCategory.hpp"
#include "Entities/Items/ItemEffect.hpp"
#include "Entities/Items/ItemStatus.hpp"
#include "Entities/Items/ItemQuality.hpp"
#include "Entities/Items/ItemMaterial.hpp"
#include "Entities/Items/ItemElement.hpp"
#include "Entities/Items/ItemSlot.hpp"
#include "Entities/Items/Items.hpp"

#include "World/TileType.hpp"
#include "World/Biome.hpp"
#include "World/Room.hpp"

/*
    *
    * Item Object Constants
    *
\*/
namespace ItemConstants {
    extern const std::vector<Item> DEFAULT_INVENTORY_STARTER_PACK;
    extern const unsigned int DEFAULT_INVENTORY_SPACE;
    extern const unsigned int DEFAULT_MAX_INVENTORY_SPACE;
    extern const std::string ITEM_NAME_EMPTY;
    extern const std::string ITEM_DESCRIPTION_EMPTY;
    extern const float ITEM_VALUE_EMPTY;
    extern const float ITEM_WEIGHT_EMPTY;


    // safely fallback to 0 across any Enum setup
    inline constexpr ItemType ITEM_TYPE_EMPTY = static_cast<ItemType>(0);
    inline constexpr ItemRarity ITEM_RARITY_EMPTY = static_cast<ItemRarity>(0);
    inline constexpr ItemEffect ITEM_EFFECT_EMPTY = static_cast<ItemEffect>(0);
    inline constexpr ItemStatus ITEM_STATUS_EMPTY = static_cast<ItemStatus>(0);
    inline constexpr ItemQuality ITEM_QUALITY_EMPTY = static_cast<ItemQuality>(0);
    inline constexpr ItemMaterial ITEM_MATERIAL_EMPTY = static_cast<ItemMaterial>(0);
    inline constexpr ItemElement ITEM_ELEMENT_EMPTY = static_cast<ItemElement>(0);
    inline constexpr ItemSlot ITEM_SLOT_EMPTY = static_cast<ItemSlot>(0);

};

/*
*
* Weapon Object Constants : Inheritance of Item Object Class
*
*/
namespace WeaponConstants {
    // DEFAULT WEAPON MELEE
    // Part of Starter Pack

    inline constexpr ItemType MELEE_DEFAULT_TYPE = static_cast<ItemType>(0);
    inline constexpr ItemCategory MELEE_DEFAULT_CATEGORY = static_cast<ItemCategory>(0);
    inline constexpr ItemMaterial MELEE_DEFAULT_MATERIAL = static_cast<ItemMaterial>(0);
    inline constexpr ItemRarity MELEE_DEFAULT_RARITY = static_cast<ItemRarity>(0);
    inline constexpr ItemSlot MELEE_DEFAULT_SLOT = static_cast<ItemSlot>(0);
    inline constexpr ItemQuality MELEE_DEFAULT_QUALITY = static_cast<ItemQuality>(0);
    inline constexpr ItemStatus MELEE_DEFAULT_STATUS = static_cast<ItemStatus>(0);
    inline constexpr ItemElement MELEE_DEFAULT_ELEMENT = static_cast<ItemElement>(0);

};

namespace WeaponRegistry {
    inline const Item WOODEN_SWORD {
        
    };
};

namespace ArmorConstants {};
namespace ConsumableConstants {};

/*
*
* Engine Object Constants
*
*/
namespace WindowConstants{
    inline const std::string WINDOW_TITLE = "Roguelite";
    inline constexpr unsigned int WINDOW_WIDTH = 1080;
    inline constexpr unsigned int WINDOW_HEIGHT = 720;
};

/*
*
* Map Object Constants 
*
*/

namespace MapConstants {
    extern const float MAP_TILE_SIZE;
    // DEFAULT SIZED MAP
    inline constexpr unsigned int DEFAULT_MAP_WIDTH = 40;
    inline constexpr unsigned int DEFAULT_MAP_HEIGHT = 30; // Pixel?
    // LARGE SIZED MAP
    inline constexpr unsigned int LARGE_MAP_WIDTH = 200;
    inline constexpr unsigned int LARGE_MAP_HEIGHT = 1000;
};

/*
*
* Room Object Constants 
*
*/

namespace RoomConstants {
    // Standard Dungeon Constants
    inline const sf::Color DEFAULT_ROOM_TILE_COLOR = sf::Color::Red;

    

};

/*
*
* Biome Object Constants 
*
*/

namespace BiomeRegistry {
    // Stone Dungeon
    inline const Biome STONE_DUNGEON = {
        "Stone Dungeon",
        sf::Color(35, 35, 45),      // Ground
        sf::Color(20, 20, 25),      // Floor paths
        sf::Color(140, 90, 40)      // Platforms
    };

    // Desert Dungeon
    inline const Biome DESERT_DUNGEON = {
        "Desert Dungeon",
        sf::Color(222, 199, 31),      // Ground
        sf::Color(194, 174, 29),      // Floor paths
        sf::Color(150, 138, 50)      // Platforms
    };

    // Forest Dungeon
    inline const Biome FOREST_DUNGEON = {
        "Forest Dungeon",
        sf::Color(63, 204, 54),      // Ground
        sf::Color(99, 230, 92),      // Floor paths
        sf::Color(36, 128, 30)      // Platforms
    };
    
    // Ice Dungeon
    inline const Biome ICE_DUNGEON = {
        "Ice Dungeon",
        sf::Color(80, 120, 160),      // Ground
        sf::Color(140, 180, 210),      // Floor paths
        sf::Color(200, 240, 255)      // Platforms
    };

    // Magma Dungeon
    inline const Biome MAGMA_DUNGEON = {
        "Magma Dungeon",
        sf::Color(43, 36, 29),      // Ground
        sf::Color(222, 105, 0),      // Floor paths
        sf::Color(102, 88, 75)      // Platforms
    };
};

/*
*
* Tile Object Constants 
*
*/

namespace TileConstants {
    // Default Tile Constants
    extern const float DEFAULT_TILE_SIZE;
    extern const sf::Vector2f DEFAULT_TILE_POSITION;
    extern const sf::Color DEFAULT_TILE_COLOR;
    extern const bool DEFAULT_TILE_IS_SOLID;

    inline constexpr TileType DEFAULT_TILE_TYPE = static_cast<TileType>(1);

};

/*
*
* Entity Object Constants
*
*/

namespace EntityConstants {
    inline const std::string DEFAULT_NAME = "Entity";
    inline const sf::Vector2f DEFAULT_POSITION = {0.0f, 0.0f};
    inline const sf::Vector2f DEFAULT_VELOCITY = {0.0f, 0.0f};

    extern const float DEFAULT_WIDTH;
    extern const float DEFAULT_HEIGHT;
    extern const float DEFAULT_HEALTH_POINTS;
    extern const float DEFAULT_PROTECTION_POINTS;
    extern const float DEFAULT_STRENGTH_POINTS;
    extern const float DEFAULT_BUFFER_STRENGTH_POINTS;
    extern const float DEFAULT_SPEED;
    extern const float DEFAULT_BUFFER_SPEED;
    extern const float DEFAULT_STAMINA;
};

/*
*
* Player Object Constants
*
*/

namespace PlayerConstants {
    inline const std::string DEFAULT_NAME = "Player";
    inline const sf::Vector2f DEFAULT_POSITION = {0.0f, 0.0f};
    inline const sf::Vector2f DEFAULT_VELOCITY = {0.0f, 0.0f};

    extern const float DEFAULT_WIDTH;
    extern const float DEFAULT_HEIGHT;
    extern const float DEFAULT_HEALTH_POINTS;
    extern const float DEFAULT_PROTECTION_POINTS;
    extern const float DEFAULT_STRENGTH_POINTS;
    extern const float DEFAULT_BUFFER_STRENGTH_POINTS;
    extern const float DEFAULT_SPEED;
    extern const float DEFAULT_BUFFER_SPEED;
    extern const float DEFAULT_STAMINA;
};



#endif