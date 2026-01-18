#include "engine.hpp"
#include <GLFW/glfw3.h>
#include <glm/fwd.hpp>
#include <glm/gtc/type_ptr.hpp>

const std::vector<float> CUBE_VERTICES = {
    // Back face
    -0.5f, -0.5f, -0.5f,  0.5f, -0.5f, -0.5f,  0.5f,  0.5f, -0.5f,
     0.5f,  0.5f, -0.5f, -0.5f,  0.5f, -0.5f, -0.5f, -0.5f, -0.5f,

    // Front face
    -0.5f, -0.5f,  0.5f,  0.5f, -0.5f,  0.5f,  0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f, -0.5f,  0.5f,  0.5f, -0.5f, -0.5f,  0.5f,

    // Left face
    -0.5f,  0.5f,  0.5f, -0.5f,  0.5f, -0.5f, -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f, -0.5f, -0.5f,  0.5f, -0.5f,  0.5f,  0.5f,

    // Right face
     0.5f,  0.5f,  0.5f,  0.5f,  0.5f, -0.5f,  0.5f, -0.5f, -0.5f,
     0.5f, -0.5f, -0.5f,  0.5f, -0.5f,  0.5f,  0.5f,  0.5f,  0.5f,

    // Bottom face
    -0.5f, -0.5f, -0.5f,  0.5f, -0.5f, -0.5f,  0.5f, -0.5f,  0.5f,
     0.5f, -0.5f,  0.5f, -0.5f, -0.5f,  0.5f, -0.5f, -0.5f, -0.5f,

    // Top face
    -0.5f,  0.5f, -0.5f,  0.5f,  0.5f, -0.5f,  0.5f,  0.5f,  0.5f,
     0.5f,  0.5f,  0.5f, -0.5f,  0.5f,  0.5f, -0.5f,  0.5f, -0.5f,
};



Engine::Engine()
    : m_window(800, 600, "KiwiCraft"), m_renderer(),m_camera(glm::vec3(0.0f,0.0f,5.0f))
{
    // Any global initialization goes here
    m_window.setupInput(&m_input);
    m_cubeMesh = std::make_unique<Mesh>(CUBE_VERTICES);

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
    m_input.processInput(m_camera, dt);
}

void Engine::render() {
    m_renderer.clear(0.1f, 0.1f, 0.1f, 1.0f);

    // draw a cube that changes color , for test only
    Shader& shader = m_renderer.getShader();
    shader.use();

    float time = static_cast<float>(glfwGetTime());

    float r = (sin(time) * 0.5f) + 0.5f;
    float g = (sin(time + 2.094f) * 0.5f) + 0.5f;
    float b = (sin(time + 4.188f) * 0.5f) + 0.5f;

    int vertexColorLocation = glGetUniformLocation(shader.ID, "ourColor");
    glUniform4f(vertexColorLocation, r, g, b, 1.0f);

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    glm::mat4 view = m_camera.getViewMatrix();
    glm::mat4 model = glm::mat4(1.0f);

    shader.setMat4("projection", glm::value_ptr(projection));
    shader.setMat4("view", glm::value_ptr(view));
    shader.setMat4("model", glm::value_ptr(model));

    m_cubeMesh->draw();

    m_window.swapBuffers();
}
