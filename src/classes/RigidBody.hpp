#ifndef RigidBody_H
#define RigidBody_H 

#include "Vector3f.hpp"
#include "Matrix3f.hpp"
#include "Quaternion.hpp"

class RigidBody {
  private:
    Vector3f m_forces;  // World space
    Vector3f m_torque;  // Body space
  public:
    float mass; // Kg
    Vector3f position; // World space
    Quaternion orientation; // World space
    Vector3f velocity; // World space, meter/second
    Vector3f angularVelocity; // World space, radian/second
    Matrix3f inertiaTensor, inverseInertia; // Inertia tensor, world space
    bool applyGravity = true;

    RigidBody();
    ~RigidBody();
    Vector3f transform_direction(const Vector3f& direction) const;
    Vector3f reverse_transform_direction(const Vector3f& direction) const;
    Vector3f get_point_velocity(const Vector3f& point) const;
    void add_force_at_point(const Vector3f& force, const Vector3f& point);
    void add_relative_force(const Vector3f& force);
    void update(float deltaTime);
};

#endif
