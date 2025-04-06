# C++ Template for 2D/3D Games

A modern C++ game development template using Raylib and ImGui. This template provides a solid foundation for creating 2D/3D games and cross-platform applications with a clean, organized project structure.

## Requirements
To build and run this template, you will need the following:

- Modern C++ (C++20) – The template is designed for C++20 for better features and optimizations.
- CMake (version 3.16+) – For cross-platform build system support.


## Included Dependencies
This template relies on the following already included third-party libraries for a smooth game development experience:
- [Raylib](https://github.com/raysan5/raylib) (version 5.5) – A simple and easy-to-use library for graphics, audio, and input handling.
- [Dear ImGui](https://github.com/ocornut/imgui) (version 1.91.9b) – A bloat-free immediate mode GUI library.

## Getting Started
### 1. Get the Template
Clone the repository to your desired location or download it as a .zip file:

```bash
git clone https://github.com/CL0001/raylib-cpp-project-template.git
```

### 2. Customize the Project Name and Description
Open the CMakeLists.txt file in the root of the project and edit the project name and description:

```cmake
project("YourProjectName" VERSION 0.1.0 DESCRIPTION "Your Project Description" LANGUAGES CXX)
```

Replace:
- `YourProjectName` with your desired project name.
- `Your Project Description` with a brief description of your project.

### 3. Write Your Code and Add Assets
Create your source files in the source directory and your header files in the headers directory for better organization. Add your assets (images, sounds, etc.) into the assets directory. It's also a good practice to document your project, so you can use the docs directory to store your .md files explaining the logic and other details.

### 4. Build and Run the Project
For Linux/macOS, or a Windows terminal like Git Bash:

**Initial setup:** Configure the project and generate build files. Run this once after cloning the repository:
```bash
rm -rf build && mkdir build && cd build && cmake .. && cmake --build . && ./Debug/YourProjectName.exe && cd ..
```

**Subsequent builds:** After the initial configuration and when `CMakeLists.txt` has not changed, you can simply run:
```bash
cmake --build build && ./build/Debug/YourProjectName.exe
```

> Note: Make sure to replace `YourProjectName.exe` with your actual executable name if you've customized it.
