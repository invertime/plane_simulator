#ifndef Quaternion_H
#define Quaternion_H


#include "Vector3f.hpp"
class Quaternion {
  public:
    int test;
    Vector3f operator*(const Vector3f v) const;
    Quaternion inverse(void) const;
};

#endif // !QUATERNION_H
