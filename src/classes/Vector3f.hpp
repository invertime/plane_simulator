#ifndef Vector3f_H
#define Vector3f_H

class Vector3f 
{
  public:
    Vector3f();
    Vector3f(float x, float y, float z);
    Vector3f(Vector3f const& other);
    ~Vector3f();
  private: 
    float x,y,z;
};

#endif // !Vector3_C
