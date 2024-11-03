#include "RigidBody.hpp"
#include "Quaternion.hpp"
#include "Vector3f.hpp"

Vector3f RigidBody::transform_direction(const Vector3f &direction) const {
    return this->orientation * direction;
}

Vector3f
RigidBody::reverse_transform_direction(const Vector3f &direction) const {
    return this->orientation.inverse() * direction;
}

Vector3f RigidBody::get_point_velocity(const Vector3f &point) const {
    return reverse_transform_direction(this->velocity) +
           crossProduct(this->angularVelocity, point);
}

void RigidBody::add_force_at_point(const Vector3f &force,
                                   const Vector3f &point) {
    m_forces += transform_direction(force);
    m_torque += crossProduct(point, force);
}

void RigidBody::add_relative_force(const Vector3f &force) {
    m_forces += transform_direction(force);
}

void RigidBody::update(float dt) {

    // integrate position
    Vector3f acceleration = m_forces / mass;
    if (applyGravity)
        acceleration.y -= 9.81f;
    velocity += acceleration * dt;
    position += velocity * dt;

    // integrate orientation
    angularVelocity +=
        inverseInertia *
        (m_torque -
         crossProduct(angularVelocity, inertiaTensor * angularVelocity) * dt);
    orientation +=
        (orientation * Quaternion(0.0f, angularVelocity)) * (0.5f * dt);
};
