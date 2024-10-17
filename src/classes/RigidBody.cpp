#include "RigidBody.hpp"
#include "Quaternion.hpp"
#include "Vector3f.hpp"

Vector3f RigidBody::transform_direction(const Vector3f& direction) const {
  return this->orientation * direction;
}

Vector3f RigidBody::reverse_transform_direction(const Vector3f& direction) const {
  return this->orientation.inverse() * direction;
}

Vector3f RigidBody::get_point_velocity(const Vector3f& point) const{
  return reverse_transform_direction(this->velocity); //+ crossProduct(this->angularVelocity, point)
}

void RigidBody::update(float deltaTime){
  return;
};
