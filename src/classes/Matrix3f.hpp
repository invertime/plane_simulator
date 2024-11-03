#pragma once

#include "Vector3f.hpp"

class Matrix3f 
{
  public:
    Matrix3f();
    Matrix3f(Vector3f x, Vector3f y, Vector3f z);
    Matrix3f(Matrix3f const& other);
    ~Matrix3f();

    Vector3f x,y,z;
};

Vector3f operator*(const Matrix3f m, Vector3f v);

Matrix3f diagMat(Vector3f v);
