#ifndef PLAYERINVENTORY_HPP
#define PLAYERINVENTORY_HPP

#include <vector>

#include "Entities/Items/Items.hpp"

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