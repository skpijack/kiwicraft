#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f));

    glm::mat4 getViewMatrix() const;

    // Movement
    void processKeyboard(glm::vec3 direction, float deltaTime);

    // Rotation
    void processMouseMovement(float xoffset, float yoffset);

    glm::vec3 getFront() const { return m_front; }
    glm::vec3 getUp() const { return m_up; }

private:
    void updateCameraVectors();

    glm::vec3 m_position;
    glm::vec3 m_front;
    glm::vec3 m_up;
    glm::vec3 m_right;
    glm::vec3 m_worldUp;

    // Euler Angles
    float m_yaw;
    float m_pitch;

    float m_speed;
    float m_sensitivity;
};
