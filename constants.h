#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Items.h"
#include <vector>
#include <string>

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
    extern const unsigned int ITEM_VALUE_EMPTY;
    extern const unsigned int ITEM_WEIGHT_EMPTY;

    inline constexpr ItemType ITEM_TYPE_EMPTY;
    inline constexpr ItemRarity ITEM_RARITY_EMPTY;
    inline constexpr ItemEffect ITEM_EFFECT_EMPTY;
    inline constexpr ItemStatus ITEM_STATUS_EMPTY;
    inline constexpr ItemQuality ITEM_QUALITY_EMPTY;
    inline constexpr ItemMaterial ITEM_MATERIAL_EMPTY;
    inline constexpr ItemElement ITEM_ELEMENT_EMPTY;
    inline constexpr ItemSlot ITEM_SLOT_EMPTY;

};

/*
*
* Weapon Object Constants : Inheritance of Item Object Class
*
*/
namespace WeaponConstants {
    // DEFAULT WEAPON MELEE
    // Part of Starter Pack

    inline constexpr ItemType MELEE_DEFAULT_TYPE;
    inline constexpr ItemCategory MELEE_DEFAULT_CATEGORY;
    inline constexpr ItemMaterial MELEE_DEFAULT_MATERIAL;
    inline constexpr ItemRarity MELEE_DEFAULT_RARITY;
    inline constexpr ItemSlot MELEE_DEFAULT_SLOT;
    inline constexpr ItemQuality MELEE_DEFAULT_QUALITY;
    inline constexpr ItemStatus MELEE_DEFAULT_STATUS;
    inline constexpr ItemElement MELEE_DEFAULT_ELEMENT;
};

namespace ArmorConstants {};
namespace ConsumableConstants {};

#endif