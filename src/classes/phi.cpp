#pragma once

#include "Vector3f.hpp"
#include <assert.h>
#include <cmath>

namespace phi {

Vector3f X_AXIS = {1.0f, 0.0f, 0.0f};
Vector3f Y_AXIS = {0.0f, 1.0f, 0.0f};
Vector3f Z_AXIS = {0.0f, 0.0f, 1.0f};

Vector3f FORWARD = X_AXIS;
Vector3f UP = Y_AXIS;
Vector3f RIGHT = Z_AXIS;
Vector3f BACKWARD = -X_AXIS;
Vector3f DOWN = -Y_AXIS;
Vector3f LEFT = -Z_AXIS;

float degrees(float rad) { return rad * 180 / M_PI; }

/* from the ISA */

float get_air_temperature(float altitude) {
    assert(0.0f <= altitude && altitude <= 11000.0f);
    return 288.15f - 0.0065f * altitude;
}

float get_air_density(float altitude) {
    assert(0.0f <= altitude && altitude <= 11000.0f);
    float temperature = get_air_temperature(altitude);
    float pressure =
        101325.0f * std::pow(1 - 0.0065f * (altitude / 288.15f), 5.25f);
    return 0.00348f * (pressure / temperature);
}

template<typename T, typename  U>
T lerp (T a, T b, U t){
    return a*(1.0f-t)+b*t;
}

float inverseLerp(float a, float b, float v) {
    return (v-a)/(b-a);
}

} // namespace phi