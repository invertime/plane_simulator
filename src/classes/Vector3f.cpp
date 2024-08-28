#include "Vector3f.hpp"

Vector3f::Vector3f(): x(0), y(0), z(0) {}

Vector3f::Vector3f(float x, float y, float z): x(x), y(y), z(z) {}

Vector3f::Vector3f(Vector3f const& other): x(other.x), y(other.y), z(other.z) {}

Vector3f::~Vector3f() {
}
