#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "SFML/Graphics.hpp"

// Include core graphics headers

#include "Entities/Entity.hpp"
#include "Systems/PlayerInventory.hpp"

#include <vector>
#include <string>

class Player : public Entity{
    private: 
        unsigned int score;
        unsigned int level;
        
        PlayerInventory inventory;
        
    public:
        Player();
        ~Player() override;

        void update(float dt) override;

        
        PlayerInventory& getInventory();
};

#endif
