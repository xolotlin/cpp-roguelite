# C++ Roguelite (Actual Game Name Here)

### Architecture
* **Language:** C++17
* **Graphics:** SFML 2.x (Graphics, Window, System)
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

