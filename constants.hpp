#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include "Items.hpp"
#include <vector>
#include <string>

/*
    *
    * Item Object Constants Declarations
    *
\*/
namespace ItemConstants {
    
    extern const std::vector<Item> DEFAULT_INVENTORY_STARTER_PACK;
    extern const unsigned int DEFAULT_INVENTORY_SPACE;
    extern const unsigned int DEFAULT_MAX_INVENTORY_SPACE;

    extern const std::string ITEM_NAME_EMPTY;
    extern const std::string ITEM_DESCRIPTION_EMPTY;
    extern const unsigned int ITEM_VALUE_EMPTY;
    extern const unsigned int ITEM_WEIGHT_EMPTY;

    inline constexpr ItemType ITEM_TYPE_EMPTY = ItemType::EMPTY;
    inline constexpr ItemRarity ITEM_RARITY_EMPTY = ItemRarity::NONE;
    inline constexpr ItemEffect ITEM_EFFECT_EMPTY = ItemEffect::NONE;
    inline constexpr ItemStatus ITEM_STATUS_EMPTY = ItemStatus::NONE;
    inline constexpr ItemQuality ITEM_QUALITY_EMPTY = ItemQuality::NONE;
    inline constexpr ItemMaterial ITEM_MATERIAL_EMPTY = ItemMaterial::NONE;
    inline constexpr ItemElement ITEM_ELEMENT_EMPTY = ItemElement::NONE;
    inline constexpr ItemSlot ITEM_SLOT_EMPTY = ItemSlot::NONE;

};

/*
*
* Weapon Object Constants Declarations : Inheritance of Item Object Class
*
*/
namespace WeaponConstants {
    // DEFAULT WEAPON MELEE
    // Part of Starter Pack

    inline constexpr ItemType MELEE_DEFAULT_TYPE = ItemType::WEAPON;
    inline constexpr ItemCategory MELEE_DEFAULT_CATEGORY = ItemCategory::MELEE;
    inline constexpr ItemMaterial MELEE_DEFAULT_MATERIAL = ItemMaterial::NONE;
    inline constexpr ItemRarity MELEE_DEFAULT_RARITY = ItemRarity::COMMON;
    inline constexpr ItemSlot MELEE_DEFAULT_SLOT = ItemSlot::WEAPON;
    inline constexpr ItemQuality MELEE_DEFAULT_QUALITY = ItemQuality::AVERAGE;
    inline constexpr ItemStatus MELEE_DEFAULT_STATUS = ItemStatus::NEW;
    inline constexpr ItemElement MELEE_DEFAULT_ELEMENT = ItemElement::NONE;
};

namespace ArmorConstants {
    // DEFAULT ARMOR 
    // Part of Starter Pack

    inline constexpr ItemType ARMOR_DEFAULT_TYPE = ItemType::ARMOR;
    inline constexpr ItemCategory ARMOR_DEFAULT_CATEGORY = ItemCategory::LIGHT;
    inline constexpr ItemMaterial ARMOR_DEFAULT_MATERIAL = ItemMaterial::NONE;
    inline constexpr ItemRarity ARMOR_DEFAULT_RARITY = ItemRarity::COMMON;
    inline constexpr ItemSlot ARMOR_DEFAULT_SLOT = ItemSlot::CHEST;
    inline constexpr ItemQuality ARMOR_DEFAULT_QUALITY = ItemQuality::AVERAGE;
    inline constexpr ItemStatus ARMOR_DEFAULT_STATUS = ItemStatus::NEW;
    inline constexpr ItemElement ARMOR_DEFAULT_ELEMENT = ItemElement::NONE;
};

namespace ConsumableConstants {
    // DEFAULT CONSUMABLE
    // Part of Starter Pack
    
};

/*
*
* Engine Object Constants Declarations
*
*/
namespace EngineConstants {};

/*
*
* Window Object Constants Declarations
*
*/
namespace WindowConstants{
    extern const std::string WINDOW_TITLE;
    extern const unsigned int WINDOW_WIDTH;
    extern const unsigned int WINDOW_HEIGHT;
};

#endif