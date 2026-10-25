#ifndef ENGINE_HPP
#define ENGINE_HPP

#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Entities/Player.hpp"
#include "World/Map.hpp"

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
        void cameraMovement(float dt);

        sf::RenderWindow window; // create window object
        sf::View camera; // create camera object
        float cameraSpeed = 500.0f;

        bool isPaused; // Pause any core processes toward client
        bool isVsyncEnabled; // is Vertitcal Sync enabled
        bool isMouseCursorVisible; // is mouse cursor visiable
        int windowFrameRateLimit; // Frame rate limit: 60 fps

        Map map; // create Map object

        sf::Clock deltaClock;
        Player player;
};

#endif