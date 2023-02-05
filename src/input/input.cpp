#include "input.hpp"

namespace core {
namespace input {

Input::Input(GLFWwindow* handle)
{
    for(int i = 0; i < MAX_KEYS; i++)
    {
        keys[i] = false;
    }
    
    for(int i = 0; i < MAX_BUTTONS; i++)
    {
        buttons[i] = false;
    }
    
    glfwSetWindowUserPointer(handle, this);
    
}

Input::~Input()
{
    
}

bool Input::isKeyPressed(int keyCode)
{
    if(keyCode >= MAX_KEYS) return false;
    return keys[keyCode];
}

bool Input::isButtonPressed(int button)
{
    if(button >= MAX_BUTTONS) return false;
    return buttons[button];
}

void Input::getMousePossition(double& x, double& y)
{
    this->x = x;
    this->y = y;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Input* input = (Input*)glfwGetWindowUserPointer(window);
    
    if((input->keys[key] = (action != GLFW_RELEASE)))
    {
        std::cout << key << " is pressed" << std::endl;
        std::cout << (GLchar)key << " is pressed" << std::endl;
    }
}

void button_callback(GLFWwindow* window, int button, int action, int mods)
{
    Input* input = (Input*)glfwGetWindowUserPointer(window);
    
    if((input->buttons[button] = (action != GLFW_RELEASE)))
    {
        std::cout << button << " is pressed" << std::endl;
//        std::cout << (GLchar)button << " is pressed" << std::endl;
    }
}

void mouse_position_callback(GLFWwindow* window, double x_pos, double y_pos)
{
    Input* input = (Input*)glfwGetWindowUserPointer(window);
    
    input->x = x_pos;
    input->y = y_pos;
    std::cout << "X: " << input->x << " - Y: " << input->y << std::endl;
}

}
}
