#pragma once

#include "window.hpp"
#include "../renderer/renderer.hpp"

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

    float m_deltaTime = 0.0f;
    float m_lastFrame = 0.0f;
};
