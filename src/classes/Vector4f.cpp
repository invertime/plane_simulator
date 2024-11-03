#include "Vector4f.hpp"

#include <cmath>
#include <math.h>

Vector4f::Vector4f() : w(0), x(0), y(0), z(0) {}

Vector4f::Vector4f(float w, float x, float y, float z)
    : w(w), x(x), y(y), z(z) {}

Vector4f::Vector4f(Vector4f const &other)
    : w(other.w), x(other.x), y(other.y), z(other.z) {}

Vector4f::~Vector4f() {}

Vector4f Vector4f::operator+(const Vector4f v) const {
    return {w + v.w, x + v.x, y + v.y, z + v.z};
}

void Vector4f::operator+=(const Vector4f v) {
    w += v.w;
    x += v.x;
    y += v.y;
    z += v.z;
}

Vector4f Vector4f::operator-(void) const { return {-w, -x, -y, -z}; }

Vector4f Vector4f::operator-(const Vector4f v) const {
    return {w - v.w, x - v.x, y - v.y, z - v.z};
}

float Vector4f::length() const {
    return sqrt(pow(w, 2) + pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector4f Vector4f::normalise(void) const { return *this / this->length(); }

float dotProduct(Vector4f const &v1, Vector4f const &v2) {
    return v1.w * v2.w + v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector4f operator*(const Vector4f v, float e) {
    return {v.w * e, v.x * e, v.y * e, v.z * e};
}

Vector4f operator/(const Vector4f v, float e) {
    return {v.w / e, v.x / e, v.y / e, v.z / e};
}
