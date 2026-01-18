#include "engine.hpp"
#include <GLFW/glfw3.h> // for glfwGetTime

Engine::Engine()
    : m_window(800, 600, "KiwiCraft"), m_renderer()
{
    // Any global initialization goes here
}

Engine::~Engine() {}

void Engine::run() {
    while (!m_window.shouldClose()) {
        float currentFrame = static_cast<float>(glfwGetTime());
        m_deltaTime = currentFrame - m_lastFrame;
        m_lastFrame = currentFrame;

        update(m_deltaTime);

        render();
    }
}

void Engine::update(float dt) {
    m_window.pollEvents();
    // We will add camera movement here next!
}

void Engine::render() {
    m_renderer.clear(0.5f, 0.8f, 0.9f, 1.0f);

    m_window.swapBuffers();
}
