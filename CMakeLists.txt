cmake_minimum_required(VERSION 3.15)
project(kiwicraft VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)

add_executable(${PROJECT_NAME}
    src/main.cpp
    src/engine/window.cpp
    src/engine/engine.cpp
    src/engine/input_handler.cpp
    src/renderer/shader.cpp
    src/renderer/renderer.cpp
    src/renderer/camera.cpp
    src/renderer/mesh.cpp)

file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/bin/shaders")

configure_file(shaders/vertex.glsl "${CMAKE_BINARY_DIR}/bin/shaders/vertex.glsl" COPYONLY)
configure_file(shaders/fragment.glsl "${CMAKE_BINARY_DIR}/bin/shaders/fragment.glsl" COPYONLY)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw
    glm::glm
    glad::glad
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
