#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

#include <vector>

#include "Items.h"

class PlayerInventory {
    private:
        std::vector<Item> inventoryItems;
        unsigned int currentInventorySpace;
        unsigned int maxInventorySpace;
    public:
        PlayerInventory();
        ~PlayerInventory();

        void addItem(const Item& item);
        void removeItem(const Item& item);
        unsigned int getCurrentInventorySpace() const;
        unsigned int getMaximumInventorySpace() const;
        std::vector<Item> getInventoryItems() const;
};

#endif