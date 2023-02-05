#include <iostream>
#include "graphics/window.hpp"
#include "includeHeader.hpp"
#include "graphics/shader.hpp"

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace::core;
using namespace::graphics;
using namespace::math;

vec2 core::math::operator+(vec2& left, const vec2& right);
vec2 core::math::operator-(vec2& left, const vec2& right);
vec2 core::math::operator*(vec2& left, const vec2& right);
vec2 core::math::operator/(vec2& left, const vec2& right);

vec2 vectorA(1.0f, 2.0f);
vec2 vectorB(1.0f, 2.0f);

int main(int argc, const char * argv[]) {
    Window window("Window", 960, 540);
    glClearColor(0.2f, 0.3f, 0.5f, 1.0f);

    GLfloat verticies[] =
    {
        0, 0, 0,
        8, 0, 0,
        0, 3, 0,
        0, 3, 0,
        8, 3, 0,
        8, 0, 0
    };
    
    Shader shader("/Users/vklimov/dev/Wingine/Wingine/Wingine/src/shaders/vertex.vert",
                  "/Users/vklimov/dev/Wingine/Wingine/Wingine/src/shaders/fragment.frag");
    shader.enable();
    
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
    
    mat4 ortho = mat4::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
    mat4 translation = mat4::translation(vec3(4, 3, 0));
    vec2 light = vec2(4.0f, 1.5f);
    vec4 color = vec4(0.2f, 0.4f, 0.7f, 1.0f);
    
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderID, "projection_matrix"), 1, GL_FALSE, ortho.elements);
    glUniformMatrix4fv(glGetUniformLocation(shader.shaderID, "model_matrix"), 1, GL_FALSE, translation.elements);
    glUniform2f(glGetUniformLocation(shader.shaderID, "light_pos"), light.x, light.y);
    glUniform4f(glGetUniformLocation(shader.shaderID, "col"), color.x, color.y, color.z, color.w);
    
//    mat4 identity = mat4::identity(1.0f);
//    mat4 position = mat4::translation(vec3(3,4,0));
    
//    position *= identity;
    
    
    
    while (!window.closed()) {
//        std::cout << vectorA + vectorB << std::endl;
        window.mainLoop();
    }
    return 0;
}
