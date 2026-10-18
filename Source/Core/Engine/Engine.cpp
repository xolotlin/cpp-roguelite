#include "Core/Engine/Engine.hpp"
#include "Core/Constants.hpp"

#include <iostream>


Engine::Engine()
    : window(sf::VideoMode({WindowConstants::WINDOW_WIDTH,
                            WindowConstants::WINDOW_HEIGHT}),
                            WindowConstants::WINDOW_TITLE) {}

void Engine::run() {
    while(window.isOpen()) {

        sf::Time elapsed = deltaClock.restart();
        float dt = elapsed.asSeconds();
        processEvents();
        if (!isPaused) {
            update(dt);
        }
        render();
    }
}

void Engine::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                std::cout << "Window close requested. Closing Window" << std::endl;
                break;
                
            case sf::Event::LostFocus:
                isPaused = true;
                std::cout << "Window Lost Focus. Pausing game" << std::endl;

                break;

            case sf::Event::GainedFocus:
                isPaused = false;
                std::cout << "Window Gained Focus. Resuming game" << std::endl;
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

void Engine::update(float dt) {
    // Update player, enemies, map, events, etc..
    player.update(dt);
    player.loadAssets();
}

void Engine::render() {
    window.clear(sf::Color::Black);

    map.render(window);

    player.render(window);

    window.display();
}