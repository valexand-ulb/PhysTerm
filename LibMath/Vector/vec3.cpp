//
// Created by alex on 8/01/24.
//

#include "vec3.h"

#include <cmath>
#include <iostream>


vec3 vec3::rotationX(float pitch) const {
    float cos_pitch = std::cos(pitch);
    float sin_pitch = std::sin(pitch);
    float new_ty = ty * cos_pitch - tz * sin_pitch;
    float new_tz = ty * sin_pitch + tz * cos_pitch;
    return vec3(tx, new_ty, new_tz);
}

vec3 vec3::rotationY(float yaw) const {
    float cos_yaw = std::cos(yaw);
    float sin_yaw = std::sin(yaw);

    float new_tx = tx * cos_yaw + tz * sin_yaw;
    float new_tz = -tx * sin_yaw + tz * cos_yaw;
    return vec3(new_tx, ty, new_tz);
}



