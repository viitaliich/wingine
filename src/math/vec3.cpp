#include "vec3.hpp"

namespace core{
namespace math{

vec3::vec3(const float& x, const float& y, const float& z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

vec3::~vec3()
{
    
}

vec3& vec3::add(const vec3 &other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    
    return *this;
}

vec3& vec3::sub(const vec3 &other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    
    return *this;
}

vec3& vec3::mul(const vec3 &other)
{
    x *= other.x;
    y *= other.y;
    z *= other.z;
    
    return *this;
}

vec3& vec3::div(const vec3 &other)
{
    x /= other.x;
    y /= other.y;
    z /= other.z;
    
    return *this;
}

vec3 operator+(vec3 left, const vec3& right)
{
    return left.add(right);
}

vec3 operator-(vec3 left, const vec3& right)
{
    return left.sub(right);
}

vec3 operator*(vec3 left, const vec3& right)
{
    return left.mul(right);
}

vec3 operator/(vec3 left, const vec3& right)
{
    return left.div(right);
}

vec3& vec3::operator+=(const vec3 &other)
{
    return add(other);
}

vec3& vec3::operator-=(const vec3 &other)
{
    return sub(other);
}

vec3& vec3::operator*=(const vec3 &other)
{
    return mul(other);
}

vec3& vec3::operator/=(const vec3 &other)
{
    return div(other);
}

std::ostream& operator<<(std::ostream& stream, const vec3& vector)
{
    stream << "Vector: (" << vector.x << ", " << vector.y << ")";
    return stream;
}

}
}
