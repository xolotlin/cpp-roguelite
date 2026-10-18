#ifndef ENTITY_HPP
#define ENTITY_CPP

#pragma once
#include "SFML/Graphics.hpp"

#include "EntityClass.hpp"
#include "EntityRank.hpp"

#include <string>

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

        sf::Vector2f position; // current world position
        sf::Sprite sprite;
        sf::Texture texture;

        EntityClass entityClass;
        EntityRank entityRank;

    public:
        Entity();
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

        // Getter entity functions

        std::string getEntityName() const;
        float getHealthPoints() const;
        float getArmorPoints() const;
        float getStrengthPoints() const;
        float getBufferStrengthPoints() const;
        sf::Vector2f getPosition() const;
        EntityClass getClass() const;
        EntityRank getRank() const;

};

#endif