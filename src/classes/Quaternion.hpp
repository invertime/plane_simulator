#ifndef Quaternion_H
#define Quaternion_H


#include "Vector3f.hpp"
class Quaternion {
  public:
    float a, b, c, d;

    // Constructors
    Quaternion();
    Quaternion(float a, float b, float c, float d);
    Quaternion(float a, Vector3f v);

    // Operators
    Quaternion inverse(void) const;
    Quaternion operator*(const Quaternion q);
    void operator+=(const Quaternion q);


};

const Quaternion operator*(const Quaternion q, const float x);
const Vector3f operator*(const Quaternion q, const Vector3f v);

#endif // !QUATERNION_H
