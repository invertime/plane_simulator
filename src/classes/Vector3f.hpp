#pragma once

class Vector3f {
  public:
    float x, y, z;

    // Constructors
    Vector3f();
    Vector3f(float e);
    Vector3f(float x, float y, float z);
    Vector3f(Vector3f const &other);
    ~Vector3f();

    // Operators
    Vector3f operator+(const Vector3f v) const;
    void operator+=(const Vector3f v);
    Vector3f operator-(void) const;
    Vector3f operator-(const Vector3f v) const;

    float length() const;
    Vector3f normalise() const;
};

float dotProduct(Vector3f const &v1, Vector3f const &v2);
Vector3f crossProduct(Vector3f const &v1, Vector3f const &v2);
Vector3f operator*(const Vector3f v, float e);
Vector3f operator*(const float e, const Vector3f v);
Vector3f operator/(const Vector3f v, float e);
