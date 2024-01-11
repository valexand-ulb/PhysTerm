//
// Created by alex on 8/01/24.
//

#include "Triangle3D.h"

Triangle2D Triangle3D::projection(float focal_length) const {
    return Triangle2D(v1.projection(focal_length),v2.projection(focal_length),v3.projection(focal_length));
}

Triangle3D Triangle3D::translation(vec3 v) const {
    return {v1+v,v2+v,v3+v};
}

Triangle3D Triangle3D::rotateX(float pitch) const {
    return {v1.rotationX(pitch),v2.rotationX(pitch),v3.rotationX(pitch)};
}

Triangle3D Triangle3D::rotateY(float yaw) const {
    return {v1.rotationY(yaw),v2.rotationY(yaw),v3.rotationY(yaw)};
}


