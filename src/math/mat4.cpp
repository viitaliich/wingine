#include "mat4.hpp"

namespace core{
namespace math{

mat4::mat4()
{
    for(int i = 0; i < MATRIX_SIZE; i++)
    {
        elements[i] = 0.0f;
    }
}

mat4::~mat4()
{
    
}

mat4 mat4::identity(float diagonal)
{
    mat4 identity;
    
    identity.elements[0 + 0 * 4] = diagonal;
    identity.elements[1 + 1 * 4] = diagonal;
    identity.elements[2 + 2 * 4] = diagonal;
    identity.elements[3 + 3 * 4] = diagonal;
    
    return identity;
}

mat4 mat4::ortho(float left, float right, float bottom, float top, float near, float far)
{
    mat4 ortho;
    ortho.elements[0 + 0 * 4] = 2.0f / (right - left);
    ortho.elements[1 + 1 * 4] = 2.0f / (top - bottom);
    ortho.elements[2 + 2 * 4] = 2.0f / (near - far);
    ortho.elements[0 + 3 * 4] = (left + right) / (left - right);
    ortho.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
    ortho.elements[2 + 3 * 4] = (far + near) / (far - near);
    ortho.elements[3 + 3 * 4] = 1.0f;
    
    return ortho;
}

mat4 mat4::translation(const vec3 &translate)
{
    mat4 result = identity(1.0f);
    
    result.elements[0 + 3 * 4] = translate.x;
    result.elements[1 + 3 * 4] = translate.y;
    result.elements[2 + 3 * 4] = translate.z;
    
    return result;
}

mat4& mat4::mult(const mat4 &other)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            float sum = 0.0f;
            for(int e = 0; e < 4; e++)
            {
                sum += elements[j + e * 4] * other.elements[e + i * 4];
            }
            elements[j + i * 4] = sum;
        }
    }
    return *this;       // ???
}

mat4 operator*(mat4 left, const mat4& right)
{
    return left.mult(right);
}

mat4& mat4::operator*=(const mat4& other)
{
    return mult(other);
}

}
}
