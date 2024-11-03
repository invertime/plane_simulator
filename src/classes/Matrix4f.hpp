#pragma once

#include "Quaternion.hpp"
#include "Vector3f.hpp"
#include "Vector4f.hpp"

class Matrix4f {
  public:
    Vector4f w, x, y, z;

    Matrix4f();
    Matrix4f(float e);
    Matrix4f(Vector4f w, Vector4f x, Vector4f y, Vector4f z);
    Matrix4f(Quaternion q);
    Matrix4f(Matrix4f const &other);
    ~Matrix4f();

    Matrix4f operator*(const Matrix4f m);

    Matrix4f translate(const Vector3f v);
};

Vector4f operator*(const Matrix4f m, Vector4f v);
