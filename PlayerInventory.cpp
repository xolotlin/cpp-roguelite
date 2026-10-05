#include "PlayerInventory.h"
#include "constants.h"

PlayerInventory::PlayerInventory() : inventoryItems(DEFAULT_INVENTORY_STARTER_PACK), 
currentInventorySpace(DEFAULT_INVENTORY_SPACE), maxInventorySpace(DEFAULT_MAX_INVENTORY_SPACE) {}

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



/*
Twenty years from now, youll be more disapointed 
by the things you didn't do, 
then by the ones that you did do.
So throw off the bow lines, sail away from the safe harbour, 
catch the trade winds in your sails
Expl0ore, dream, discover.
*/