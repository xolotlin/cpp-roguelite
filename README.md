# C++ Roguelite

A 2D roguelite platformer game built from scratch using **C++17**, **SFML 2.6.1**, and the **CMake** build ecosystem. 

### Architecture
* **Language:** C++17
* **Graphics:** SFML 2.6.1
* **Build System:** CMake


### Prerequisites

Before installing, you need to install a C++ Compiler (`g++` or `clang`), Cmake, and SFML libraries

```bash
git clone https://github.com/xolotlin/cpp-roguelite
```

Debian-Based/Ubuntu

```bash
sudo apt update && sudo apt install build-essential libsfml-dev
mkdir build && cd build
cmake ..
make
```

#### Run Game
Once `make` finishes compiling succesfully, launch the game binary build directory
```bash
./Game
```

### Controls
* **A / Left Arrow:** Move Left
* **D / Right Arrow:** Move Right
* **W / Spacebar:** Jump

