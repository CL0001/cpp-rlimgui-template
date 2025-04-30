# C++ Template for 2D/3D Games

A modern, cross-platform C++ game development template with everything you need to get started — just write code and run it. It uses Raylib for game development and ImGui for creating graphical user interfaces. 

## Requirements
You'll need the following tools or IDEs that contains them like Microsoft Visual Studio or Xcode:

- **C++20** – The template is designed with C++20 features in mind for modern syntax and better optimizations, though older versions may still work — just try changing the `CMAKE_CXX_STANDARD` value in the `CMakeLists.txt`.
- **CMake (version 3.30+)** – Required for cross-platform builds. You can lower the required version in `CMakeLists.txt` if needed, but 3.30+ is recommended.


## Included Dependencies
This template comes with the following third-party libraries already included to streamline game development:
- **Raylib (v5.5)** – A simple and easy-to-use library for graphics, audio, and input handling.
- **Dear ImGui (v1.91.9b)** – A bloat-free, immediate mode GUI library.
- **rlImGui (main branch, commit from Mar 17, 2025)** – Acts as a bridge between Raylib and Dear ImGui, enabling the integration of ImGui-based GUIs in Raylib projects.


## Project Structure
```
.
├── assets/             # Game assets like sprites, fonts, sounds, etc.
├── build/              # Build directory (generated during the build process)
├── include/            # Header files (.h)
├── scripts/            # Setup and helper scripts for building/running
├── src/                # Source files (.cpp)
├── third_party/        # Included third-party libraries (Raylib, ImGui)
├── CMakeLists.txt      # Root CMake configuration file
└── README.md           # Project overview and usage instructions
```


## Getting Started
Microsoft Visual Studio 2022 is recommended for Windows, and Xcode is recommended for macOS. If neither of these is available, see below for instructions on building with CMake.

### 1. Download the repository:
Clone the repository to your desired location or download it as a .zip file:

```bash
git clone https://github.com/CL0001/cpp-rlimgui-template.git
```

### 2. Customize the project name and description:
Open the `CMakeLists.txt` file in the root of the project and edit the project name and description:

```cmake
project("YourProjectName" VERSION 0.1.0 DESCRIPTION "Your Project Description" LANGUAGES CXX)
```

Replace:
- `YourProjectName` with your desired project name. **Avoid spaces and special symbols, using only alphanumeric characters, hyphens, or underscores**.
- `Your Project Description` with a brief description of your project. **Spaces and special symbols are allowed here**.


## Generate Visual Studio or Xcode Solution
Run the appropriate setup script for your platform, located in the `scripts` directory. **Make sure the script has execution permission (especially for Unix-like systems).**

Running the script will create a `build` directory in the root of the project (where `CMakeLists.txt` is located), containing the generated solution files.

If you want to add new source or header files, you must first create them manually (e.g., via File Explorer) in the appropriate directories (`src/` for source files and `include/` for headers).
Then you need to re-run the setup script (which reconfigures CMake) to include the new files in the build. After that, reload the solution in your IDE to see the updates.

⚠️ **Warning:** If the configuration fails or you're seeing strange build issues, delete the `build/` directory entirely and run the appropriate setup script again from scratch.

## Configure and Build with CMake (Any editor or IDE)
**Configuration:**

Configure the project and generate build files. Run this once after cloning the repository, or when `CMakeLists.txt` has been changed, or if something fails. In the latter cases, remove the build directory and run this again:
```bash
mkdir build
cd build
cmake ..
```

⚠️ **Warning:** If the configuration fails or you're seeing strange build issues, delete the `build/` directory entirely and run the commands again from scratch.

**Build:**

After the initial configuration, you can simply run the following to rebuild the project:
```bash
cmake --build . && ./build/Debug/YourProjectName.exe
```

> Note: Make sure to replace YourProjectName.exe with your actual executable name if you've customized it.

## Template Output
After running the template, you should see a window like this:

![Image](https://github.com/user-attachments/assets/89b56cf9-fba1-4f6f-92ae-37dcfba9862a)

## Using Assets
All your game assets — including textures, fonts, audio files, and shaders — should be placed in the assets/ directory (which can be further divided into subdirectories) at the root of the project.

The template automatically provides the path to this directory using a compile-time definition called ASSETS_PATH, which is set in CMakeLists.txt:
```cmake
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_SOURCE_DIR}/assets/")
```

In your C++ code, you can use this macro to load assets in a platform-independent way:
```cpp
std::string fullPath = std::string(ASSETS_PATH) + "images/player.png";
Texture2D playerTexture = LoadTexture(fullPath.c_str());
```
