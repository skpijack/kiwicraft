# kiwicraft

voxel engine in C++ and OpenGL

Build guide
- Prerequisites: CMake (>=3.15), a C++ toolchain, Python (for Conan).

Windows
- Setup
  - Install Python and pip, then install Conan: `pip install conan`.
  - Install a C++ toolchain (e.g. Visual Studio with C++ workload).
- Build steps
  - Open a developer command prompt (MSVC).
  - Create a build directory: `mkdir build && cd build`.
  - Install dependencies: `conan install .. --build=missing`.
  - Configure with Visual Studio generator: `cmake .. -G "Visual Studio 17 2022" -A x64`.
  - Build: `cmake --build . --config Release`.
  - Run: `.
build\bin\kiwicraft.exe`.
- Notes
  - Shaders are copied to `build/bin/shaders` automatically during build.

Linux
- Prerequisites
  - Ensure Conan is installed: `pip3 install --user conan` (or via your distro).
  - Install a C++ toolchain (GCC/Clang) and CMake.
- Build steps
  - Create a build directory: `mkdir -p build && cd build`.
  - Install dependencies: `conan install .. --build=missing`.
  - Configure: `cmake .. -DCMAKE_BUILD_TYPE=Release`.
  - Build: `cmake --build .`.
  - Run: `./bin/kiwicraft` (path under `build/bin`).
