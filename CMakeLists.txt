cmake_minimum_required(VERSION 3.10)

project(Game LANGUAGES CXX)

# Set C++ Version 17 Standard Requirement
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML library package
# Graphics, Window, System and Audio Module
find_package(SFML 2 COMPONENTS graphics window system audio REQUIRED)

# Include executable files
add_executable(Game main.cpp Engine.cpp Constants.cpp)

target_link_libraries(Game PRIVATE
	sfml-graphics
	sfml-window
	sfml-system
	sfml-audio
)
