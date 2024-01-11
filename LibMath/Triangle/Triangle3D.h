//
// Created by alex on 8/01/24.
//

#ifndef TRIANGLE3D_H
#define TRIANGLE3D_H
#include "Triangle2D.h"
#include "../Vector/vec3.h"

class Triangle3D {
private:
    vec3 v1, v2, v3;
public:
    Triangle3D(vec3 v1, vec3 v2, vec3 v3): v1(v1), v2(v2), v3(v3) {}
    Triangle3D(const Triangle3D& other): v1(other.v1), v2(other.v2), v3(other.v3) {}

    Triangle2D projection(float focal_length=1.0f) const;
    Triangle3D translation(vec3 v) const;
    Triangle3D rotateX(float pitch) const;
    Triangle3D rotateY(float yaw) const;

    friend std::ostream& operator<<(std::ostream& os, const Triangle3D &t){return os <<"v1" << t.v1 << ", v2" << t.v2 << ", v3" << t.v3;}
};



#endif //TRIANGLE3D_H
