#pragma once

#include "Matrix3f.hpp"
#include "Quaternion.hpp"
#include "Vector3f.hpp"
#include "Transform.cpp"
#include <limits>

const float DEFAULT_RB_MASS = 100.0f;
const float INFINITE_RB_MASS = std::numeric_limits<float>::infinity();
const Quaternion DEFAULT_RB_ORIENTATION = Quaternion(1.0f, Vector3f());
// TODO: const Matrix3f DEFAULT_RB_INERTIA = 

class RigidBody: public Transform {
  private:
    Vector3f m_forces; // World space
    Vector3f m_torque; // Body space
  public:
    float mass = DEFAULT_RB_MASS;                             // Kg
    Vector3f position;                      // World space
    Quaternion orientation;                 // World space
    Vector3f velocity;                      // World space, meter/second
    Vector3f angularVelocity;               // World space, radian/second
    Matrix3f inertiaTensor, inverseInertia; // Inertia tensor, world space
    bool applyGravity = true;

    RigidBody();
    ~RigidBody();
    Vector3f transform_direction(const Vector3f &direction) const;
    Vector3f reverse_transform_direction(const Vector3f &direction) const;
    Vector3f get_point_velocity(const Vector3f &point) const;
    void add_force_at_point(const Vector3f &force, const Vector3f &point);
    void add_relative_force(const Vector3f &force);
    virtual void update(float deltaTime);
};
