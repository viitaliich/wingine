#include "window.hpp"
#include "../input/input.hpp"

using namespace core;
using namespace input;

void core::input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void core::input::button_callback(GLFWwindow* window, int button, int action, int mods);
void core::input::mouse_position_callback(GLFWwindow* window, double x_pos, double y_pos);

namespace core{
namespace graphics{




Window::Window(const char* name, int width, int height)
{
    this->name = name;
    this->width = width;
    this->height = height;
    if(!init())
        glfwTerminate();
}

Window::~Window()
{
    glfwTerminate();
    
}



bool Window::init()
{
    if(!glfwInit())
    {
        std::cout << "GLFW not initialised" << std::endl;
        glfwTerminate();
        return 0;
    }
    
    window = glfwCreateWindow(width, height, name, NULL, NULL);
    Input input(window);
    
    glfwMakeContextCurrent(window);
    
    glfwSetKeyCallback(window, key_callback);
//    glfwSetMouseButtonCallback(window, button_callback);
//    glfwSetCursorPosCallback(window, mouse_position_callback);
    
    if(glewInit() != GLEW_OK)
    {
        std::cout << "GLEW is not OK" << std::endl;
        return false;
    }
    
    return true;
}

void Window::update()
{
    glfwPollEvents();
    glfwSwapBuffers(window);
}

void Window::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::render()
{
//    glBegin(GL_QUADS);
//    glVertex2f(0.5f, 0.5f);
//    glVertex2f(0.5f, -0.5f);
//    glVertex2f(-0.5f, -0.5f);
//    glVertex2f(-0.5f, 0.5f);
//    glEnd();
    
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Window::mainLoop()
{
    update();
    clear();
    render();
}

bool Window::closed()
{
    return glfwWindowShouldClose(window) == 1;
}

}
}
