#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "SFML/Graphics.hpp"
#include "Entities/Entity.hpp"
#include "Systems/PlayerInventory.hpp"

#include <vector>
#include <string>

class Map;

class Player : public Entity{
    private: 
        unsigned int score;
        unsigned int level;
        
        PlayerInventory inventory;

        Map *m_mapPtr = nullptr;
        
    public:
        Player();
        Player(std::string entityName, float healthPoints, float protectionPoints, 
           float strengthPoints, float speed, sf::Vector2f position);

        
        ~Player() override;

        virtual void update(float dt) override;
        // void render (sf::RenderWindow& window) override; // uncomment if you override render
        void setMap(Map* m_mapPtr);
        
        PlayerInventory& getInventory();
};

#endif
