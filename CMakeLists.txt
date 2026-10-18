cmake_minimum_required(VERSION 3.10)

project(Game LANGUAGES CXX)

# Set C++ Version 17 Standard Requirement
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SFML library package
# Graphics, Window, System and Audio Module
find_package(SFML 2 COMPONENTS graphics window system audio REQUIRED)

# =============================
# + Source file list 
# =============================
set(CORE_SOURCES
    Source/main.cpp
    Source/Core/Engine/Engine.cpp
    Source/Core/Constants.cpp
)

set(ENTITY_SOURCES
    Source/Entities/Player.cpp
    Source/Entities/Entity.cpp
    Source/Entities/Items/Items.cpp
)

set(SYSTEM_SOURCES
    Source/Systems/PlayerInventory.cpp
)

set(WORLD_SOURCES
    Source/World/Tile.cpp
    Source/World/Map.cpp
)

# Include executable files
add_executable(Game 
    ${CORE_SOURCES}
    ${ENTITY_SOURCES}
    ${SYSTEM_SOURCES}
    ${WORLD_SOURCES}
)

# =============================
# + Target Configurations
# =============================

target_link_libraries(Game PRIVATE
	sfml-graphics
	sfml-window
	sfml-system
	sfml-audio
)

if(MSVC)
    target_compile_options(Game PRIVATE /W4 /wx)
else()
    target_compile_options(Game PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Include header files
target_include_directories(Game PRIVATE Include)

# Automatically copy Assets folder to build directory on compilation
add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_CURRENT_SOURCE_DIR}/Assets"
    "${CMAKE_CURRENT_BINARY_DIR}/Assets"
    COMMENT "Copying assets deploy folder to build dir"
)
