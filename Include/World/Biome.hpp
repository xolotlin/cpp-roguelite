#ifndef BIOME_HPP
#define BIOME_HPP

#include <SFML/Graphics.hpp>
#include <string>

struct Biome {
    std::string name;

    // Theme color palettes
    sf::Color groundColor;
    sf::Color emptySpaceColor;
    sf::Color platformColor;

    // int maxEnemiesPerRoom;
    // std::string backgroundTrackPath;
};

#endif // BIOME_HPP