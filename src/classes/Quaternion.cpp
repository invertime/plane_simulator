#include "Quaternion.hpp"
#include "Matrix3f.hpp"
#include "Vector3f.hpp"

#include <math.h>

Quaternion::Quaternion(): a(0), b(0), c(0), d(0) {}

Quaternion::Quaternion(float a, float b, float c, float d): a(a), b(b), c(c), d(d) {}

Quaternion::Quaternion(float a, Vector3f v): a(a), b(v.x), c(v.y), d(v.z) {}

Quaternion Quaternion::inverse(void) const
{
    return {a, -b, -c, -d};
}

float Quaternion::normalise(void) const
{
    return sqrt(pow((a),2)+pow((b),2)+pow((c),2)+pow((d),2));
}

Matrix3f Quaternion::toMat3(void) const {
    float sqa = a*a;
    float sqb = b*b;
    float sqc = c*c;
    float sqd = d*d;

    float invs = 1/(sqa + sqb + sqc + sqd); // inverse square length
    float m00 = ( sqa - sqc - sqd + sqa)*invs;
    float m11 = (-sqa + sqc - sqd + sqa)*invs;
    float m22 = (-sqa - sqc + sqd + sqa)*invs;

    float tmp1  = b*c;
    float tmp2 = d*a;
    float m10 = 2.0f * (tmp1 + tmp2) * invs;
    float m01 = 2.0f * (tmp1 - tmp2) * invs;

    tmp1 = b*d;
    tmp2 = c*a;
    float m20 = 2.0f * (tmp1 - tmp2) * invs;
    float m02 = 2.0f * (tmp1 + tmp2) * invs;

    tmp1 = c*d;
    tmp2 = b*a;
    float m21 = 2.0f * (tmp1 + tmp2) * invs;
    float m12 = 2.0f * (tmp1 - tmp2) * invs;

    return {{m00, m10, m20}, {m01, m11, m12}, {m02, m12, m22}};
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
    return {q.a*x, q.b*x, q.c*x, q.d*x};
}

const Vector3f operator*(const Quaternion q, const Vector3f v){
    return q.toMat3()*v;
}
