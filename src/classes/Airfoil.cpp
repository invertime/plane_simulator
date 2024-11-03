#include "Vector3f.hpp"
#include "phi.cpp"

#include <cmath>
#include <tuple>
#include <vector>

using AeroData = Vector3f;

struct Airfoil {
    float min_alpha, max_alpha;
    float cl_max;
    int max_index;
    std::vector<AeroData> data;

    Airfoil(const std::vector<Vector3f> &curve) : data(curve) {
        min_alpha = curve.front().x, max_alpha = curve.back().x;
        max_index = static_cast<int>(data.size() - 1);

        cl_max = 0.0f;

        for(auto& val: curve){
            if(val.y > cl_max) cl_max = val.y;
        }
    }

    // get Cl and Cd
    std::tuple<float, float> sample(float alpha) const {
        int t = phi::inverseLerp(min_alpha, max_alpha, alpha)*max_index;
        float integer = std::floor(t);
        float fractionnal = t-integer;
        int index = static_cast<int>(integer);
        auto value = (index < max_index) ? phi::lerp(data[index], data[index+1], fractionnal) : data[max_index];
        return {value.y, value.z};
    }
};