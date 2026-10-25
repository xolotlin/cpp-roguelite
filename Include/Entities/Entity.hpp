#ifndef ENTITY_HPP
#define ENTITY_CPP

#pragma once
#include "SFML/Graphics.hpp"

#include "World/Map.hpp"
#include "Entities/EntityClass.hpp"
#include "Entities/EntityRank.hpp"

#include <string>

class Map;

class Entity {
    protected:
        std::string entityName;
        float healthPoints;
        float protectionPoints; // From armor and other items
        float armorPoints;
        float strengthPoints;
        float bufferStrengthPoints; // increments current strength through items and other events
        float speed;
        float bufferSpeed;
        float stamina;

        // Physics & dimensions
        sf::Vector2f position; // current world position
        sf::Vector2f velocity;
        float width;
        float height;
        bool isGrounded;

        // Visuals
        sf::Sprite sprite;
        sf::Texture texture;
        sf::RectangleShape shape; // prototype box

        EntityClass entityClass;
        EntityRank entityRank;

        // Map & world
        Map* m_mapPtr = nullptr;

    public:
        Entity(); //default 
        Entity( // parameratized
            std::string entityName, 
            float healthPoints, 
            float protectionPoints, 
            float strengthPoints, 
            float bufferStrengthPoints,
            float speed,
            float bufferSpeed,
            float stamina,
            float width,
            float height,
            bool isGrounded,
            sf::Vector2f position,
            sf::Vector2f velocity
        ); 
        virtual ~Entity();

        virtual void loadAssets();                  // Loads the texture from file
        virtual void update(float dt);             // Handle input and movement logic
        virtual void render(sf::RenderWindow& window); // Draw the player to the window

        // Setter entity functions
        void setEntityName(std::string entityName);
        void setHealthPoints(float healthPoints);
        void setArmorPoints(float armorPoints);
        void setStrengthPoints(float strengthPoints);
        void setBufferStrengthPoints(float bufferStrengthPoints);
        void setPosition(float x, float y);
        void setRank(EntityRank entityRank);
        void setClass(EntityClass entityClass);
        void setMap(Map* m_mapPtr);

        // Getter entity functions

        std::string getEntityName() const;
        float getHealthPoints() const;
        float getArmorPoints() const;
        float getStrengthPoints() const;
        float getBufferStrengthPoints() const;
        float getWidth() const;
        float getHeight() const;
        sf::Vector2f getPosition() const;
        sf::Vector2f getVelocity() const;
        EntityClass getClass() const;
        EntityRank getRank() const;

        sf::RectangleShape& getShape();


};

#endif