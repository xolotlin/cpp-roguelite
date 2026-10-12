#ifndef ITEMS_HPP
#define ITEMS_HPP

#include <string>
#include <iostream>

#include "ItemType.hpp"
#include "ItemRarity.hpp"
#include "ItemCategory.hpp"
#include "ItemEffect.hpp"
#include "ItemStatus.hpp"
#include "ItemQuality.hpp"
#include "ItemMaterial.hpp"
#include "ItemElement.hpp"
#include "ItemSlot.hpp"

/*
* This class represents a default item in the game. Contains basic info about the item such as name, description, 
* value, and weighrt. This class can be extended to create more specific item types such as weapons, armor, etc.
*/
class Item {
    protected:
        std::string name;
        std::string description;
        unsigned int value;
        unsigned int weight;

        ItemType type;
        ItemRarity rarity;
        ItemEffect effect;
        ItemStatus status;
        ItemQuality quality;
        ItemMaterial material;
        ItemElement element;
        ItemSlot slot;

    public:
        Item();
        ~Item();

        void setName(const std::string& name);
        std::string getName() const;

        void setDescription(const std::string& description);
        std::string getDescription() const;

        void setValue(unsigned int value);
        unsigned int getValue() const;

        void setWeight(unsigned int weight);
        unsigned int getWeight() const;

        void setType(ItemType type);
        ItemType getType() const;

        void setRarity(ItemRarity rarity);
        ItemRarity getRarity() const;

        void setEffect(ItemEffect effect);
        ItemEffect getEffect() const;

        void setStatus(ItemStatus status);
        ItemStatus getStatus() const;

        void setQuality(ItemQuality quality);
        ItemQuality getQuality() const;

        void setMaterial(ItemMaterial material);
        ItemMaterial getMaterial() const;

        void setElement(ItemElement element);
        ItemElement getElement() const;

        void setSlot(ItemSlot slot);
        ItemSlot getSlot() const;

        void displayItemInfo() const;
        void displayItemStats() const;
        void displayItemDescription() const;
        void displayItemRarity() const;
        void displayItemEffect() const;
        void displayItemStatus() const;
        void displayItemQuality() const;
        void displayItemMaterial() const;
        void displayItemElement() const;
        void displayItemSlot() const;
        void displayItemValue() const;
        void displayItemWeight() const;
        void displayItemType() const;

};

/*
* This class represents a weapon item in the game. Inherits from the Item class and adds damage attribute.
*/
class Weapon : public Item {
    private:
        unsigned int damage;
        unsigned int range;
        unsigned int attackSpeed;
        unsigned int criticalChance;
        unsigned int durability;
        unsigned int levelRequirement;
        unsigned int classRequirement;

        bool isEnchanted;
        bool isDualWieldable;

    public:
        Weapon();
        ~Weapon();

        void setDamage(unsigned int damage);
        unsigned int getDamage() const;

        void setRange(unsigned int range);
        unsigned int getRange() const;

        void setAttackSpeed(unsigned int attackSpeed);
        unsigned int getAttackSpeed() const;

        void setCriticalChance(unsigned int criticalChance);
        unsigned int getCriticalChance() const;

        void setDurability(unsigned int durability);
        unsigned int getDurability() const;

        void setLevelRequirement(unsigned int levelRequirement);
        unsigned int getLevelRequirement() const;

        void setClassRequirement(unsigned int classRequirement);
        unsigned int getClassRequirement() const;

        void setIsEnchanted(bool isEnchanted);
        bool getIsEnchanted() const;

        void setIsDualWieldable(bool isDualWieldable);
        bool getIsDualWieldable() const;
};

/*
* This class represents a Armor item in the game. Inherits from the Item class and adds defense attribute.
*/
class Armor : public Item {
    private:
        unsigned int defense;
        unsigned int durability;
        unsigned int levelRequirement;
        unsigned int classRequirement;
        bool isEnchanted;
    public:
        Armor();
        ~Armor();

        void setDefense(unsigned int defense);
        unsigned int getDefense() const;

        void setDurability(unsigned int durability);
        unsigned int getDurability() const;

        void setLevelRequirement(unsigned int levelRequirement);
        unsigned int getLevelRequirement() const;

        void setClassRequirement(unsigned int classRequirement);
        unsigned int getClassRequirement() const;

        void setIsEnchanted(bool isEnchanted);
        bool getIsEnchanted() const;

};

/*
* This class represents a consumable item in the game. Inherits from the Item class and adds health points attribute.
*/
class Consumable : public Item {
    private:
        unsigned int healthPoints;
    public:
        Consumable();
        ~Consumable();

        void setHealthPoints(unsigned int healthPoints);
        unsigned int getHealthPoints() const;
};

#endif
    