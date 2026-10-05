#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerRanks.h"
#include "PlayerClasses.h"
#include "PlayerInventory.h"

#include <vector>
#include <string>

class Player {
    private: 
        std::string name;

        int healthPoints;
        unsigned int lives; // # of Chances after dying
        unsigned int maxHealthPoints;

        int scorePoints;
        unsigned int maxScorePoints;

        unsigned int currentLevel;
        unsigned int potentialLevel;
        unsigned int currentMaximumLevel;
        
        PlayerRank playerRank;
        PlayerClass playerClass;

        unsigned int currentInventorySpace;
        unsigned int maxInventorySpace;

        PlayerInventory inventory;
        
    public:
        Player();
        ~Player();

        void setName(std::string name);
        std::string getName() const;

        void setRank(PlayerRank rank);
        PlayerRank getRank() const;

        void setClass(PlayerClass playerClass);
        PlayerClass getClass() const;

        void setHealthPoints(int healthPoints);
        int getHealthPoints() const;

        void setLives(unsigned int lives);
        unsigned int getLives() const;

        void setScorePoints(int scorePoints);
        int getScorePoints() const;

        void setCurrentLevel(unsigned int currentLevel);
        unsigned int getCurrentLevel() const;

        void setPotentialLevel(unsigned int potentialLevel);
        unsigned int getPotentialLevel() const;

        void setCurrentMaximumLevel(unsigned int currentMaximumLevel);
        unsigned int getCurrentMaximumLevel() const;

        void setCurrentInventorySpace(unsigned int currentInventorySpace);
        unsigned int getCurrentInventorySpace() const;

        void setMaximumInventorySpace(unsigned int maxInventorySpace);
        unsigned int getMaximumInventorySpace() const;
};

#endif
