#include "window.hpp"


Window::Window(int width, int height, const char* title){
    if (!glfwInit()){
        std::cerr << "Failed to initialize glfw" << std::endl;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(width,height,title,NULL,NULL);
    if (!m_window){
        std::cerr << "Failed to create window " << std::endl;
        glfwTerminate();
    }

    glfwMakeContextCurrent(m_window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cerr << "Failed to init GLAD" << std::endl;
    }
    glEnable(GL_DEPTH_TEST);
    glViewport(0,0,width,height);
}

Window::~Window(){
    glfwDestroyWindow(m_window);
    glfwTerminate();
}
void Window::setupInput(InputHandler* handler) {
    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetWindowUserPointer(m_window, handler);

    glfwSetCursorPosCallback(m_window, [](GLFWwindow* w, double xpos, double ypos) {
        auto* ih = static_cast<InputHandler*>(glfwGetWindowUserPointer(w));
        ih->handleMouse(xpos, ypos);
    });

    glfwSetKeyCallback(m_window, [](GLFWwindow* w, int key, int scancode, int action, int mods) {
        auto* ih = static_cast<InputHandler*>(glfwGetWindowUserPointer(w));
        ih->handleKey(key, scancode, action, mods);
    });
}

bool Window::shouldClose(){return glfwWindowShouldClose(m_window);}
void Window::swapBuffers(){glfwSwapBuffers(m_window);}
void Window::pollEvents(){glfwPollEvents();}
void Window::clear(float r, float g, float b, float a){
    glClearColor(r,g,b,a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
