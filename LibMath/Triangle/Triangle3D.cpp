//
// Created by alex on 8/01/24.
//

#include "Triangle3D.h"

Triangle2D Triangle3D::projection() {
    return Triangle2D(v1.project(),v2.project(),v3.project());
}

void Triangle3D::translate(vec3 v) {
    v1 += v;
    v2 += v;
    v3 += v;
}

void Triangle3D::rotateX(float pitch) {
    v1.rotationX(pitch);
    v2.rotationX(pitch);
    v3.rotationX(pitch);
}

void Triangle3D::rotateY(float yaw) {
    v1.rotationY(yaw);
    v2.rotationY(yaw);
    v3.rotationY(yaw);
}


