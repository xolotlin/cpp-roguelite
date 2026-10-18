#ifndef ENGINE_HPP
#define ENGINE_HPP

#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Player.hpp"
#include "Map.hpp"

#include <string>
#include <memory>

class Engine {
    public:
        Engine();
        virtual ~Engine() = default;

        void run();

    private:
        void processEvents();
        void update(float dt);
        void render();

        sf::RenderWindow window;
        bool isPaused; // Pause any core processes toward client

        Map map;

        sf::Clock deltaClock;
        Player player;
};

#endif