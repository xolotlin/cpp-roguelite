cmake_minimum_required(VERSION 3.10)

project(Game LANGUAGES CXX)

# Set C++ Version 17 Standard Requirement
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML library package
# Graphics, Window, System and Audio Module
find_package(SFML 2 COMPONENTS graphics window system audio REQUIRED)

# Include executable files
add_executable(Game 
    main.cpp 
    Engine.cpp 
    Player.cpp
    Entity.cpp
    Constants.cpp
    PlayerInventory.cpp
    Items.cpp
)

target_link_libraries(Game PRIVATE
	sfml-graphics
	sfml-window
	sfml-system
	sfml-audio
)

# Automatically copy Assets folder to build directory on compilation
add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/Assets"
    "${CMAKE_CURRENT_BINARY_DIR}/Assets"
    COMMENT "Copying assets deploy folder to build dir"
)