#pragma once

#include "window.hpp"
#include "../renderer/renderer.hpp"
#include "input_handler.hpp"
#include "../renderer/mesh.hpp"
#include <memory>
#include <vector>

class Engine {
public:
    Engine();
    ~Engine();
    void run();

private:
    void update(float dt);
    void render();

    Window m_window;
    Renderer m_renderer;
    InputHandler m_input;
    std::unique_ptr<Mesh> m_cubeMesh;
    Camera m_camera;

    float m_deltaTime = 0.0f;
    float m_lastFrame = 0.0f;
};
