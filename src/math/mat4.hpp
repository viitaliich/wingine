#pragma once

#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

#define MATRIX_SIZE 4 * 4

namespace core {
namespace math {

struct mat4
{
    float elements[MATRIX_SIZE];
    mat4();
    ~mat4();
    
    static mat4 identity(float diagonal);
    static mat4 ortho(float left, float right, float bottom, float top, float near, float far);
    static mat4 translation(const vec3& translate);
    
    mat4& mult(const mat4& other);
    friend mat4 operator*(mat4 left, const mat4& right);
    mat4& operator*=(const mat4& other);
};

}
}

