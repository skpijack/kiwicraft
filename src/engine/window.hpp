#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "input_handler.hpp"
#include <iostream>

class Window{
    public:
    Window(int width,int height, const char* title);
    ~Window();

    bool shouldClose();
    void swapBuffers();
    void pollEvents();
    void clear(float r , float g, float b, float a);
    void setupInput(InputHandler* handler);

    GLFWwindow* getHandle() { return m_window; }
    GLFWwindow* getGLFWwindow() {return m_window;}
private:
    GLFWwindow* m_window;
};
