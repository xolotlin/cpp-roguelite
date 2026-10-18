#include "Systems/PlayerInventory.hpp"
#include "Core/Constants.hpp"

PlayerInventory::PlayerInventory() :
    inventoryItems(ItemConstants::DEFAULT_INVENTORY_STARTER_PACK), 
    currentInventorySpace(ItemConstants::DEFAULT_INVENTORY_SPACE), 
    maxInventorySpace(ItemConstants::DEFAULT_MAX_INVENTORY_SPACE) 
{}

PlayerInventory::~PlayerInventory() {}

void PlayerInventory::addItem(const Item& item) {}

void PlayerInventory::removeItem(const Item& item) {}

unsigned int PlayerInventory::getCurrentInventorySpace() const {
    return currentInventorySpace;
}

unsigned PlayerInventory::getMaximumInventorySpace() const {
    return maxInventorySpace;
}

std::vector<Item> PlayerInventory::getInventoryItems() const {
    return inventoryItems;
}
