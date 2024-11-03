#include "Vector3f.hpp"

#include <cmath>
#include <math.h>

Vector3f::Vector3f() : x(0), y(0), z(0) {}

Vector3f::Vector3f(float e): x(e), y(e), z(e) {}

Vector3f::Vector3f(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3f::Vector3f(Vector3f const &other)
    : x(other.x), y(other.y), z(other.z) {}

Vector3f::~Vector3f() {}

Vector3f Vector3f::operator+(const Vector3f v) const {
    return {x + v.x, y + v.y, z + v.z};
}

void Vector3f::operator+=(const Vector3f v) {
    x += v.x;
    y += v.y;
    z += v.z;
}

Vector3f Vector3f::operator-(void) const { return {-x, -y, -z}; }

Vector3f Vector3f::operator-(const Vector3f v) const {
    return {x - v.x, y - v.y, z - v.z};
}

float Vector3f::length() const {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3f Vector3f::normalise(void) const { return *this / this->length(); }

float dotProduct(Vector3f const &v1, Vector3f const &v2) { 
    return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z; 
}

Vector3f crossProduct(Vector3f const &u, Vector3f const &v) {
    return {u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z,
            u.x * v.y - u.y * v.x};
}

Vector3f operator*(const Vector3f v, float e) {
    return {v.x * e, v.y * e, v.z * e};
}

Vector3f operator*(const float e, const Vector3f v) {
    return {v.x * e, v.y * e, v.z * e};
}

Vector3f operator/(const Vector3f v, float e) {
    return {v.x / e, v.y / e, v.z / e};
}
