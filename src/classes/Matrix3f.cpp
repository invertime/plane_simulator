#include "Matrix3f.hpp"

Matrix3f::Matrix3f(): x(Vector3f(0,0,0)), y(Vector3f(0,0,0)), z(Vector3f(0,0,0)) {};

Matrix3f::Matrix3f(Vector3f x, Vector3f y, Vector3f z): x(x), y(y), z(z) {};

Matrix3f::Matrix3f(Matrix3f const& other): x(other.x), y(other.y), z(other.z) {};

Matrix3f::~Matrix3f(){

};

Vector3f operator*(const Matrix3f m, Vector3f v)
{
    return {
        m.x.x*v.x + m.y.x*v.y + m.z.x*v.z,
        m.x.y*v.x + m.y.y*v.y + m.z.y*v.z,
        m.x.z*v.x + m.y.z*v.y + m.z.z*v.z
    };
}
