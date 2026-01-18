#pragma once

#include "shader.hpp"
#include <glad/glad.h>

class Renderer {
public:
    Renderer();
    ~Renderer();

    void clear(float r, float g, float b, float a);

    void draw(unsigned int vao, int vertexCount);

    // Getter so the Engine can pass matrices to the shader
    Shader& getShader() { return m_shader; }

private:
    Shader m_shader;
};
