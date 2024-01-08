//
// Created by alex on 8/01/24.
//

#include "vec3.h"

#include <cmath>
#include <iostream>


void vec3::rotationX(float pitch) {
    float cos_pitch = std::cos(pitch);
    float sin_pitch = std::sin(pitch);
    ty = ty * cos_pitch - tz * sin_pitch;
    tz = ty * sin_pitch + tz * cos_pitch;
}

void vec3::rotationY(float yaw) {
    float cos_yaw = std::cos(yaw);
    float sin_yaw = std::sin(yaw);

    tx = tx * cos_yaw + tz * sin_yaw;
    tz = -tx * sin_yaw + tz * cos_yaw;
}



