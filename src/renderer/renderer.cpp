#include "renderer.hpp"

Renderer::Renderer()
    : m_shader("shaders/vertex.glsl", "shaders/fragment.glsl")
{
    glEnable(GL_DEPTH_TEST);
}

Renderer::~Renderer() {
    // Shader destructor handles its own cleanup
}

void Renderer::clear(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(unsigned int vao, int vertexCount) {
    m_shader.use();
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, vertexCount);

    glBindVertexArray(0);
}
