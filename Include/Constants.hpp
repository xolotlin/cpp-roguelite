#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include "SFML/Graphics.hpp"

#include <vector>
#include <string>

#include "ItemType.hpp"
#include "ItemRarity.hpp"
#include "ItemCategory.hpp"
#include "ItemEffect.hpp"
#include "ItemStatus.hpp"
#include "ItemQuality.hpp"
#include "ItemMaterial.hpp"
#include "ItemElement.hpp"
#include "ItemSlot.hpp"
#include "Items.hpp"

#include "TileType.hpp"

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

namespace ArmorConstants {};
namespace ConsumableConstants {};

/*
*
* Engine Object Constants
*
*/
namespace WindowConstants{
    inline const std::string WINDOW_TITLE = "Roguelite";
    inline constexpr unsigned int WINDOW_WIDTH = 800;
    inline constexpr unsigned int WINDOW_HEIGHT = 600;
};

/*
*
* Map Object Constants 
*
*/

namespace MapConstants {
    extern const float MAP_TILE_SIZE;
    // DEFAULT SIZED MAP
    inline constexpr unsigned int DEFAULT_MAP_WIDTH = 100;
    inline constexpr unsigned int DEFAULT_MAP_HEIGHT = 500; // Pixel?
    // LARGE SIZED MAP
    inline constexpr unsigned int LARGE_MAP_WIDTH = 200;
    inline constexpr unsigned int LARGE_MAP_HEIGHT = 1000;
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



#endif