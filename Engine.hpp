#ifndef ENGINE_HPP
#define ENGINE_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <string>
#include <memory>

class Engine {
    public:
        Engine();
        virtual ~Engine() = default;

        void run();

    private:
        void processEvents();
        void update();
        void render();

        sf::RenderWindow window;
};

#endif