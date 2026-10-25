#include <SFML/Window.hpp>

#include "Core/Engine/Engine.hpp"
#include "Core/Constants.hpp"

#include <iostream>

Engine::Engine()
: window(
    sf::VideoMode({WindowConstants::WINDOW_WIDTH,
    WindowConstants::WINDOW_HEIGHT}),
    WindowConstants::WINDOW_TITLE, 
    sf::Style::Default
), camera(sf::FloatRect(0.0f, 0.0f, 800.0f, 600.0f)),
isPaused(false),
isVsyncEnabled(false),
isMouseCursorVisible(true),
windowFrameRateLimit(60)
{
    window.setMouseCursorVisible(isMouseCursorVisible);
    
    if (isVsyncEnabled) {
        window.setVerticalSyncEnabled(true);
    } else {
        window.setFramerateLimit(windowFrameRateLimit);
    }

    player.loadAssets();

    player.setMap(&map);
    player.setPosition(map.getSpawnPosition().x, map.getSpawnPosition().y);
}

void Engine::run() {
    while(window.isOpen()) {
        // Calculate dynamic elasped time at the start of every loop frame
        sf::Time elapsed = deltaClock.restart();
        float dt = elapsed.asSeconds();

        processEvents();
        if (!isPaused) {
            cameraMovement(dt);
            update(dt);
        }

        render();
    }
}

void Engine::cameraMovement(float dt) {
    sf::Vector2f movement(0.0f, 0.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        movement.y -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        movement.y += 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        movement.x -= 1.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        movement.x += 1.f;

    // Apply movement scaled by delta time and camera speed
    if (movement.x != 0.f || movement.y != 0.f) {
        // Normalize vector slightly or just move directly
        camera.move(movement * cameraSpeed * dt);
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
    // map.update(dt); // implement animated tiles later
    camera.setCenter(player.getPosition());
}

void Engine::render() {
    window.clear(sf::Color::Black);
    window.setView(camera); // Activate camera view

    map.render(window);
    player.render(window);

    // Draw UI elements (health bars or text)
    // window.setView(window.getDefaultView());

    window.display();
}