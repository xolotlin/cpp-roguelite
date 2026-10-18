#include "Entities/Items/Items.hpp"
#include "Core/Constants.hpp"

using namespace ItemConstants;
using namespace WeaponConstants;

/*
* Implementation of the Item class and its member functions.
*/

Item::Item() : name(ITEM_NAME_EMPTY), description(ITEM_DESCRIPTION_EMPTY), value(ITEM_VALUE_EMPTY), weight(ITEM_WEIGHT_EMPTY), 
type(ITEM_TYPE_EMPTY), rarity(ITEM_RARITY_EMPTY), effect(ITEM_EFFECT_EMPTY), 
status(ITEM_STATUS_EMPTY), quality(ITEM_QUALITY_EMPTY), material(ITEM_MATERIAL_EMPTY), 
element(ITEM_ELEMENT_EMPTY), slot(ITEM_SLOT_EMPTY) {}

Item::~Item() {}

void Item::setName(const std::string& name) {
    if(name.empty())
        this->name = ITEM_NAME_EMPTY;
    else
        this->name = name;
}

void Item::setDescription(const std::string& description) {
    if (description.empty())
        this->description = ITEM_DESCRIPTION_EMPTY;
    else
        this->description = description;
}

void Item::setValue(unsigned int value) {
    if (value >= 0)
        this->value = value;
    else
        std::cerr << "Error: Current value: " << value << " needs to be greater than or equal to zero." << std::endl;
}

void Item::setWeight(unsigned int weight) {
    this->weight = weight;
}

void Item::setType(ItemType type) {
    this->type = type;
}

void Item::setRarity(ItemRarity rarity) {
    this->rarity = rarity;
}

void Item::setEffect(ItemEffect effect) {
    this->effect = effect;
}

void Item::setStatus(ItemStatus status) {
    this->status = status;
}

void Item::setQuality(ItemQuality quality) {
    this->quality = quality;
}

void Item::setMaterial(ItemMaterial material) {
    this->material = material;
}

void Item::setElement(ItemElement element) {
    this->element = element;
}

void Item::setSlot(ItemSlot slot) {
    this->slot = slot;
}

void Item::displayItemInfo() const {
    std::cout << "Item Name: " << name << std::endl;
    std::cout << "Item Description: " << description << std::endl;
    std::cout << "Item Value: " << value << std::endl;
    std::cout << "Item Weight: " << weight << std::endl;
    std::cout << "Item Type: " << static_cast<int>(type) << std::endl;
    std::cout << "Item Rarity: " << static_cast<int>(rarity) << std::endl;
    std::cout << "Item Effect: " << static_cast<int>(effect) << std::endl;
    std::cout << "Item Status: " << static_cast<int>(status) << std::endl;
    std::cout << "Item Quality: " << static_cast<int>(quality) << std::endl;
    std::cout << "Item Material: " << static_cast<int>(material) << std::endl;
    std::cout << "Item Element: " << static_cast<int>(element) << std::endl;
    std::cout << "Item Slot: " << static_cast<int>(slot) << std::endl;
}

void Item::displayItemStats() const {
    std::cout << "Item Value: " << value << std::endl;
    std::cout << "Item Weight: " << weight << std::endl;
    std::cout << "Item Type: " << static_cast<int>(type) << std::endl;
    std::cout << "Item Rarity: " << static_cast<int>(rarity) << std::endl;
    std::cout << "Item Effect: " << static_cast<int>(effect) << std::endl;
    std::cout << "Item Status: " << static_cast<int>(status) << std::endl;
    std::cout << "Item Quality: " << static_cast<int>(quality) << std::endl;
    std::cout << "Item Material: " << static_cast<int>(material) << std::endl;
    std::cout << "Item Element: " << static_cast<int>(element) << std::endl;
    std::cout << "Item Slot: " << static_cast<int>(slot) << std::endl;
}

void Item::displayItemDescription() const {
    std::cout << "Item Description: " << description << std::endl;
}

void Item::displayItemRarity() const {
    std::cout << "Item Rarity: " << static_cast<int>(rarity) << std::endl;
}

void Item::displayItemEffect() const {
    std::cout << "Item Effect: " << static_cast<int>(effect) << std::endl;
    
}

void Item::displayItemStatus() const {
    std::cout << "Item Status: " << static_cast<int>(status) << std::endl;
}

void Item::displayItemQuality() const {
    std::cout << "Item Quality: " << static_cast<int>(quality) << std::endl;
}

void Item::displayItemMaterial() const {
    std::cout << "Item Material: " << static_cast<int>(material) << std::endl;
}

void Item::displayItemElement() const {
    std::cout << "Item Element: " << static_cast<int>(element) << std::endl;
}

void Item::displayItemSlot() const {
    std::cout << "Item Slot: " << static_cast<int>(slot) << std::endl;
}


void Item::displayItemValue() const {
    std::cout << "Item Value: " << static_cast<int>(value) << std::endl;
}

void Item::displayItemWeight() const {
    std::cout << "Item Weight: " << static_cast<int>(weight) << std::endl;
}

void Item::displayItemType() const {
    std::cout << "Item Type: " << static_cast<int>(type) << std::endl;
}

/*
* ================================================================
* Implementation of the Weapon Class and its member functions.
* ================================================================
*/

Weapon::Weapon() : damage(), range(), attackSpeed(), criticalChance(), 
durability(), levelRequirement(), classRequirement() {}

Weapon::~Weapon() {}

void Weapon::setDamage(unsigned int damage) {
    this->damage = damage;
}

unsigned int Weapon::getDamage() const {
    return damage;
}

void Weapon::setRange(unsigned int range) {
    this->range = range;
}
unsigned int Weapon::getRange() const {
    return range;
}

void Weapon::setAttackSpeed(unsigned int attackSpeed) {
    if (attackSpeed = 0)
        this->attackSpeed = 1;
    else
        this->attackSpeed = attackSpeed;
}
unsigned int Weapon::getAttackSpeed() const {
    return attackSpeed;
}

void Weapon::setCriticalChance(unsigned int criticalChance) {
    if (criticalChance > 100)
        this->criticalChance = 100;
    else
        this->criticalChance = criticalChance;
}
unsigned int Weapon::getCriticalChance() const {
    return criticalChance;
}

void Weapon::setDurability(unsigned int durability) {
    this->durability = durability;
}
unsigned int Weapon::getDurability() const {
    return durability;
}

void Weapon::setLevelRequirement(unsigned int levelRequirement) {
    this->levelRequirement = levelRequirement;
}
unsigned int Weapon::getLevelRequirement() const {
    return levelRequirement;
}

void Weapon::setClassRequirement(unsigned int classRequirement) {
    this->classRequirement = classRequirement;
}
unsigned int Weapon::getClassRequirement() const {
    return classRequirement;
}

void Weapon::setIsEnchanted(bool isEnchanted) {
    this->isEnchanted = isEnchanted;
}
bool Weapon::getIsEnchanted() const {
    return isEnchanted;
}

void Weapon::setIsDualWieldable(bool isDualWieldable) {
    this->isDualWieldable = isDualWieldable;
}
bool Weapon::getIsDualWieldable() const {
    return isDualWieldable;
}

/* ================================================================
* Implementation of the Armor Class and its member functions.
* =================================================================
*/

void Armor::setDefense(unsigned int defense) {
    this->defense = defense;
}

unsigned int Armor::getDefense() const {
    return defense;
}

void Armor::setDurability(unsigned int durability) {
    this->durability = durability;
}

unsigned int Armor::getDurability() const {
    return durability;
}

void Armor::setLevelRequirement(unsigned int levelRequirement) {
    this->levelRequirement = levelRequirement;
}

unsigned int Armor::getLevelRequirement() const {
    return levelRequirement;
}

void Armor::setClassRequirement(unsigned int classRequirement) {
    this->classRequirement = classRequirement;
}

unsigned int Armor::getClassRequirement() const {
    return classRequirement;
}