#pragma once

#include <GL/glew.h>
#include "../utils/utils.hpp"

namespace core {
namespace graphics{

class Shader
{
public:
    GLuint shaderID;
    const char* vertexPath;
    const char* fragmentPath;
    
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();
    
    void enable();
    void disable();
    
private:
    GLuint load();
    
    
};


}
}
