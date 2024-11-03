#include "Matrix4f.hpp"
#include "Quaternion.hpp"
#include "Vector3f.hpp"


#include "phi.cpp"

struct Transform{
    Vector3f position;
    Quaternion rotation;

    Transform(): position(), rotation(1.0f, 0.0f, 0.0f, 0.0f) {}
    Transform(const Vector3f& p, const Quaternion& o): position(p), rotation(o) {}

    Matrix4f matrix() const { return  Matrix4f(1.0f).translate(position)*Matrix4f(rotation); }

    Vector3f transform_direction(const Vector3f direction) const { return rotation * direction; }

    Vector3f inverse_transform_direction(const Vector3f direction) const {
        return rotation.inverse() * direction;
    }

    Vector3f up() const { return transform_direction(phi::UP); }
    Vector3f right() const { return transform_direction(phi::RIGHT); }
    Vector3f forward() const { return transform_direction(phi::FORWARD); }

};