#pragma once

class Vector4f {
  public:
    float w, x, y, z;

    // Constructors
    Vector4f();
    Vector4f(float w, float x, float y, float z);
    Vector4f(Vector4f const &other);
    ~Vector4f();

    // Operators
    Vector4f operator+(const Vector4f v) const;
    void operator+=(const Vector4f v);
    Vector4f operator-(void) const;
    Vector4f operator-(const Vector4f v) const;

    float length() const;
    Vector4f normalise() const;
};

float dotProduct(Vector4f const &v1, Vector4f const &v2);
Vector4f operator*(const Vector4f v, float e);
Vector4f operator/(const Vector4f v, float e);
