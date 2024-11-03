#pragma once

#include "Vector3f.hpp"
typedef void CollisionCallback(const Vector3f point, const Vector3f normal);

struct Collider {
    CollisionCallback* on_collision = nullptr;
};

struct Contact {
    Collider *a, *b;
    float restitution_coeff;
};
