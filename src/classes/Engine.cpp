#include "RigidBody.hpp"
#include "Vector3f.hpp"

struct Engine {
    float throttle = 0.25f;
    Vector3f relativePosition = Vector3f();

    virtual void apply_force(RigidBody *rigid_body, float dt) = 0;        // thrust is applied to the center of gravity and does not produce torque
};