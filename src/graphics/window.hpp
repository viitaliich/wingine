#pragma once

#include <iostream>

//#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>


#define internal static
#define local_persist static
#define global_variable static

namespace core {
namespace graphics {

class Window
{
private:
    const char* name;
    int width;
    int height;
    GLFWwindow* window;
    
public:
    Window(const char* name, int width, int height);
    ~Window();
    
    bool closed();
    void mainLoop();
    
private:
    bool init();
    void update();
    void clear();
    void render();
    
};

}
}
