#include "Engine.hpp"
#include "constants.hpp"

#include <iostream>


Engine::Engine()
    : window(sf::VideoMode({WindowConstants::WINDOW_WIDTH,
                            WindowConstants::WINDOW_HEIGHT}),
                            WindowConstants::WINDOW_TITLE) {}

void Engine::run() {
    while(window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Engine::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
                
            case sf::Event::Closed:
                window.pause();
                break;

            case sf::Event::GainedFocus:
                window.resume();
                break;

            case sf::Event::KeyPressed:
                // Handle key presses here, e.g.:
                // if (event.key.code == sf::Keyboard::Escape) // Open Game menu
                break;
                
            default:
                break;
        }
    }
}

void Engine::update() {
    // Update player, enemies, map, events, etc..
}

void Engine::render() {
    window.clear(sf::Color::Black);
    window.display();
}