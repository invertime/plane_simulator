#include <vector>

#include "Matrix3f.hpp"
#include "RigidBody.hpp"
#include "Collider.hpp"
#include "Wing.cpp"
#include "Engine.cpp"

struct Airplane : public RigidBody {
    float throttle = 0.25f;
    std::vector<Engine *> engines;
    std::vector<Wing> wings;

    Airplane(float mass_, const Matrix3f inertia_, std::vector<Wing> wings_, std::vector<Engine *> engines_, Collider *collider_)
        : RigidBody({.mass = mass_, .inertia = inertia_, .collider = collider_}), wings(wings_), engines(engines_) {}

    void update(float dt) override {
        for (auto &wing : wings) {
            wing.apply_forces(this, dt);
        }

        for(auto engine: engines){
            engine->throttle = throttle;
            engine->apply_force(this, dt);
        }

        RigidBody::update(dt);
    }
};