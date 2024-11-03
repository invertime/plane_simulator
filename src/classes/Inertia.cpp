#include "Matrix3f.hpp"
#include "Vector3f.hpp"
#include <numeric>
#include <vector>

namespace inertia {


struct Element {
    Vector3f size;
    Vector3f position;  // Position in design coordinates
    Vector3f inertia;   // Moment of inertia
    Vector3f offset;    // offset from center of gravity
    float mass;
    float volume() const { return size.x * size.y * size.z; }
};


// cuboid moment of inertia
Vector3f cuboid(float mass, const Vector3f& size){
    float x = size.x, y = size.y, z = size.z;
    return Vector3f(y*y + z*z, x*x + z*z, x*x + y*y) * (1.0f / 12.0f) * mass;
}

// sphere moment of inertia
Vector3f sphere(float mass, float radius) {
    return Vector3f((2.0f / 5.0f) * mass * radius*radius);
}

Matrix3f tensor(const Vector3f moment_of_inertia) {return diagMat(moment_of_inertia);}

void set_uniform_density(std::vector<Element>& elements, float total_mass){
    auto f = [](float s, auto& e) { return s +  e.volume(); };
    float total_volume = std::accumulate(elements.begin(), elements.end(), 0.0f,f);

    for(auto& element : elements){
        element.mass = (element.volume() / total_volume) * total_mass;
    }
}

Matrix3f tensor(std::vector<Element>& elements, bool precomputed_offset = false, Vector3f* cg = nullptr){
    float Ixx = 0, Iyy = 0, Izz = 0;
    float Ixy = 0, Yxz = 0, Iyz = 0;

    float mass = 0;
    Vector3f moment_of_inertia(0.0f);

    for(const auto& element : elements) {
        mass += element.mass;
        moment_of_inertia += element.mass * element.position;
    }

    const auto center_of_gravity = moment_of_inertia / mass;
}

} // namespace inertia