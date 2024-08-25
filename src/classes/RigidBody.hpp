#ifndef POINT_H
#define POINT_H 

class RigidBody {
public:
  Vector3f position;
  Vector3f velocity;
  Vector3f angularVelocity;
  float mass;
  Matrix3f inertiaTensor;

  RigidBody();
  ~RigidBody();
  void applyForce(const Vector3f& force);
  void applyTorque(const Vector3f& torque);
  void update(float deltaTime);
};

#endif
