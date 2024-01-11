//
// Created by alex on 11/01/24.
//

#ifndef CAMERA_H
#define CAMERA_H
#include "LibMath/Vector/vec3.h"


class Camera {
private:
    vec3 position;
    float pitch, yaw;
    float focal_length;
public:
    Camera(vec3 position, float pitch, float yaw, float focal_length=1.0f): position(position), pitch(pitch), yaw(yaw), focal_length(focal_length) {}

    vec3 getPosition() const {return position;}
    float getPitch() const {return pitch;}
    float getYaw() const {return yaw;}
    float getFocalLength() const {return focal_length;}
};



#endif //CAMERA_H
