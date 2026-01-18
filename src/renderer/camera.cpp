#include "camera.hpp"

Camera::Camera(glm::vec3 position)
    : m_position(position), m_worldUp(0.0f, 1.0f, 0.0f), m_yaw(-90.0f), m_pitch(0.0f), m_speed(2.5f), m_sensitivity(0.1f)
{
    updateCameraVectors();
}

void Camera::processMouseMovement(float xoffset, float yoffset) {
    xoffset *= m_sensitivity;
    yoffset *= m_sensitivity;

    m_yaw   += xoffset;
    m_pitch += yoffset;

    if (m_pitch > 89.0f)  m_pitch = 89.0f;
    if (m_pitch < -89.0f) m_pitch = -89.0f;

    updateCameraVectors();
}

void Camera::updateCameraVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    front.y = sin(glm::radians(m_pitch));
    front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_front = glm::normalize(front);

    m_right = glm::normalize(glm::cross(m_front, m_worldUp));
    m_up    = glm::normalize(glm::cross(m_right, m_front));
}

glm::mat4 Camera::getViewMatrix() const {
    return glm::lookAt(m_position, m_position + m_front, m_up);
}

void Camera::processKeyboard(glm::vec3 direction, float deltaTime) {
    m_position += direction * m_speed * deltaTime;
}
