#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "../renderer/camera.hpp"

class InputHandler {
public:
    InputHandler();

    void handleMouse(double xpos, double ypos);
    void handleKey(int key, int scancode, int action, int mods);
    void processInput(Camera& camera, float dt);

    float getMouseOffsetX() { float o = m_offsetX; m_offsetX = 0; return o; }
    float getMouseOffsetY() { float o = m_offsetY; m_offsetY = 0; return o; }
    bool isKeyPressed(int key);

private:
    float m_lastX = 400.0f;
    float m_lastY = 300.0f;
    float m_offsetX = 0.0f;
    float m_offsetY = 0.0f;
    bool m_firstMouse = true;

    // Keyboard data
    bool m_keys[1024];
};
