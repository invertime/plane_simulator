#ifndef Matrix3f_H
#define Matrix3f_H

#include "Vector3f.hpp"

class Matrix3f 
{
  public:
    Matrix3f();
    Matrix3f(Vector3f x, Vector3f y, Vector3f z);
    Matrix3f(Matrix3f const& other);
    ~Matrix3f();
  private: 
    Vector3f x,y,z;
};

#endif // !Matrix3f_C
