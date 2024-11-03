#include "RigidBody.hpp"
#include "Vector3f.hpp"
#include "phi.cpp"
#include "Airfoil.cpp"

#include <algorithm>
#include <cmath>

struct Wing {

    const float area;
    const float wingspan;
    const float chord;
    const float aspect_ratio;
    const Airfoil *airfoil;
    const Vector3f normal;
    const Vector3f center_of_pressure;
    const float flap_ratio; // percentage of wing that is part of the flap
    const float efficiency_factor = 1.0f;

    float control_input = 0.0f;

    Wing(const Vector3f position, float span, float chord,
         const Airfoil *airfoil, const Vector3f normal,
         float flap_ratio = 0.25f)
        : airfoil(airfoil), center_of_pressure(position), area(span * chord),
          chord(chord), wingspan(span), normal(normal),
          aspect_ratio(pow(span, 2) / area), flap_ratio(flap_ratio) {}

    // controls how much the wing is deflected
    void set_control_input(float input) {
        control_input = std::clamp(input, -1.0f, 1.0f);
    }

    // compute and apply aerodynamic forces
    void apply_forces(RigidBody *rigid_body, float dt) {
        Vector3f local_velocity =
            rigid_body->get_point_velocity(center_of_pressure);
        float speed = local_velocity.length();

        if (speed <= 1.0f)
            return;

        // drag acts in the opposite direction of velocit
        Vector3f drag_direction = (-local_velocity).normalise();

        // lift is always perpendicular to drag
        Vector3f lift_direction =
            crossProduct(crossProduct(drag_direction, normal), drag_direction)
                .normalise();

        // angle between chord line and air flow
        float angle_of_attack =
            phi::degrees(std::asin(dotProduct(drag_direction, normal)));

        // sample aerodynamic coefficients
        auto [lift_coeff, drag_coeff] = airfoil->sample(angle_of_attack);

        if (flap_ratio > 0.0f) {
            float deflection_ratio = control_input;

            // lift coefficient changes based on flap deflection
            float delta_lift_coeff =
                sqrt(flap_ratio) * airfoil->cl_max * deflection_ratio;
            lift_coeff += delta_lift_coeff;
        }

        // induced drag, increases with lift
        float induced_drag_coeff =
            pow(lift_coeff, 2) / (M_PI * aspect_ratio * efficiency_factor);
        drag_coeff += induced_drag_coeff;

        // air density depends on altitude
        float air_density = phi::get_air_density(rigid_body->position.y);

        float dynamic_pressure = 0.5f * pow(speed, 2) * air_density * area;

        Vector3f lift = lift_direction * lift_coeff * dynamic_pressure;
        Vector3f drag = drag_direction * drag_coeff * dynamic_pressure;

        // aerodynamic forces are applied at the center of pressure
        rigid_body->add_force_at_point(lift + drag, center_of_pressure);
    }
};
