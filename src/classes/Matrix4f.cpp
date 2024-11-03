#include "Matrix4f.hpp"
#include "Vector4f.hpp"

Matrix4f::Matrix4f(): w(Vector4f(0,0,0,0)), x(Vector4f(0,0,0,0)), y(Vector4f(0,0,0,0)), z(Vector4f(0,0,0,0)) {};

Matrix4f::Matrix4f(float e): w({e, 0, 0, 0}),x({0, e, 0, 0}),y({0, 0, e, 0}),z({0, 0, 0, e}) {};

Matrix4f::Matrix4f(Vector4f w, Vector4f x, Vector4f y, Vector4f z): w(w), x(x), y(y), z(z) {};

Matrix4f::Matrix4f(Quaternion q): w({q.a, -q.b, -q.c, -q.d}), x({q.b, q.a, -q.d, q.c}), y({q.c, q.d, q.a, -q.b}), z({q.d, -q.c, q.b, q.a}) {};

Matrix4f::Matrix4f(Matrix4f const& other): w(other.w), x(other.x), y(other.y), z(other.z) {};

Matrix4f::~Matrix4f(){

};

Matrix4f Matrix4f::translate(Vector3f v){
    return  {w, x, y, {v.x, v.y, v.z, z.z}};
}

Vector4f operator*(const Matrix4f m, Vector4f v)
{
    return {
        m.w.w*v.w + m.x.w*v.x + m.y.w*v.y + m.z.w*v.z,
        m.w.x*v.w + m.x.x*v.x + m.y.x*v.y + m.z.x*v.z,
        m.w.y*v.w + m.x.y*v.x + m.y.y*v.y + m.z.y*v.z,
        m.w.z*v.w + m.x.z*v.x + m.y.z*v.y + m.z.z*v.z
    };
}
