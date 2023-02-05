#pragma once

#include "../graphics/window.hpp"

#define MAX_KEYS 1000
#define MAX_BUTTONS 32


namespace core {
namespace input {

class Input
{
private:
    bool keys[MAX_KEYS];
    bool buttons[MAX_BUTTONS];
    
    double x, y;
    
public:
    Input(GLFWwindow* handle);
    ~Input();
    
    bool isKeyPressed(int keyCode);
    bool isButtonPressed(int button);
    void getMousePossition(double& x, double& y);
  
private:
    friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    friend void button_callback(GLFWwindow* window, int button, int action, int mods);
    friend void mouse_position_callback(GLFWwindow* window, double x_pos, double y_pos);
};

}
}
