#include "input_handler.hpp"
#include <GLFW/glfw3.h>

InputHandler::InputHandler(){
    for (int i = 0;i < 1024;i++){
        m_keys[i] = false;
    }
}

void InputHandler::handleMouse(double xpos, double ypos){
    if (m_firstMouse){
        m_lastX = (float)xpos;
        m_lastY = (float)ypos;
        m_firstMouse = false;
    }

    m_offsetX = (float)xpos - m_lastX;
    m_offsetY = m_lastY - (float)ypos;

    m_lastX = (float)xpos;
    m_lastY = (float)ypos;
}

void InputHandler::handleKey(int key, int scancode, int action, int mods){
    if (key >= 0 && key < 1024){
        if (action == GLFW_PRESS)
            m_keys[key] = true;
        else if (action == GLFW_RELEASE)
            m_keys[key] = false;
    }
}

bool InputHandler::isKeyPressed(int key) {
    return (key >= 0 && key < 1024) ? m_keys[key] : false;
}

void InputHandler::processInput(Camera& camera, float dt) {
    // 1. Handle Mouse Look
    camera.processMouseMovement(getMouseOffsetX(), getMouseOffsetY());

    // 2. Handle Movement
    glm::vec3 front = camera.getFront();
    glm::vec3 right = glm::normalize(glm::cross(front, camera.getUp()));

    if (isKeyPressed(GLFW_KEY_W)) camera.processKeyboard(front, dt);
    if (isKeyPressed(GLFW_KEY_S)) camera.processKeyboard(-front, dt);
    if (isKeyPressed(GLFW_KEY_D)) camera.processKeyboard(right, dt);
    if (isKeyPressed(GLFW_KEY_A)) camera.processKeyboard(-right, dt);
}
