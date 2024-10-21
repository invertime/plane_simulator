#include "Quaternion.hpp"

Quaternion::Quaternion(): a(0), b(0), c(0), d(0) {}

Quaternion::Quaternion(float a, float b, float c, float d): a(a), b(b), c(c), d(d) {}

Quaternion::Quaternion(float a, Vector3f v): a(a), b(v.x), c(v.y), d(v.z) {}

Quaternion Quaternion::inverse(void) const
{
    return Quaternion();
}

Quaternion Quaternion::operator*(const Quaternion q)
{
    return {
        a*q.a - b*q.b - c*q.c - d*q.d,
        a*q.b + b*q.a + c*q.d - d*q.c,
        a*q.c - b*q.d + c*q.a + d*q.b,
        a*q.d + b*q.c - c*q.b + d*q.a
    };
}

void Quaternion::operator+=(const Quaternion q)
{
    a+=q.a;
    b+=q.b;
    c+=q.c;
    d+=q.d;
}

const Quaternion operator*(const Quaternion q, const float x)
{
    return Quaternion();
}

const Vector3f operator*(const Quaternion q, const Vector3f v){
    return Vector3f();
}
