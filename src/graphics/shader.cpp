#include "shader.hpp"
#include <iostream>

namespace core {
namespace graphics {

Shader::Shader(const char* vertexPath, const char* fragmentPath) :
    vertexPath(vertexPath),
    fragmentPath(fragmentPath)
{
    shaderID = load();
    
}

Shader::~Shader()
{
    glDeleteProgram(shaderID);
}

GLuint Shader::load()
{
    GLuint program = glCreateProgram();
    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
    
    std::string vertexSrc =read_file(vertexPath);
    std::string fragmentSrc =read_file(fragmentPath);
    const char* vertexSource = vertexSrc.c_str();
    const char* fragmentSource = fragmentSrc.c_str();
    
    glShaderSource(vertex, 1, &vertexSource, NULL);
    glShaderSource(fragment, 1, &fragmentSource, NULL);
    glCompileShader(vertex);
    glCompileShader(fragment);
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    
    glLinkProgram(program);
    glValidateProgram(program);
    
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    
    return program;
}

void Shader::enable()
{
    glUseProgram(shaderID);
}

void Shader::disable()
{
    glUseProgram(0);
}

}
}
