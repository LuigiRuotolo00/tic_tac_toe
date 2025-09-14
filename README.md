# tic_tac_toe
a simple Tic-tac-toe in C language

## About This Project
This project was developed as a personal exercise during my high school years to practice C and game development fundamentals. It was one of my first attempts at learning core programming concepts.

## Project Description
This project is inspired by the classic Tic-tac-toe paper-and-pencil game in a text-based format using ASCII characters.

## Requirements
- `C` compiler (e.g., GCC/Clang for Linux, MinGW or MSYS2 for Windows)
- **CMake** (>= 3.22.1)
- Command-line terminal (Linux terminal, Windows Command Prompt, PowerShell)

## Setup and Installation

1. **Clone the repository** and navigate to the project directory:
   ```bash
   git clone https://github.com/LuigiRuotolo00/tic_tac_toe.git
   cd tic_tac_toe

### Compile on Linux
1. **Open the folder in the terminal**, generate the MakeFile
   ```bash
   cmake -S . -B release

2. **Compile the game**
   ```bash
   cmake --build release

### Compile on Windows
1. **Open the folder in the terminal**, generate the MakeFile
   ```bash
   cmake -G "MinGW Makefiles" -S . -B release

2. **Compile the game**
   ```bash
   cmake --build release
