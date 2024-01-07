//
// Created by alex on 5/01/24.
//

#include "basicFunction.h"


bool basicFunction::isPointInTriangle(const vec2& v, const Triangle& t) {
    float s1 = t.P3().y() - t.P1().y();
    float s2 = t.P3().x() - t.P1().x();
    float s3 = t.P2().y() - t.P1().y();
    float s4 = v.y() - t.P1().y();

    float w1 = (t.P1().x() * s1 + s4 * s2 - v.x() * s1) / (s3 * s2 - (t.P2().x() - t.P1().x()) * s1);
    float w2 = (s4 - w1 * s3) / s1;

    return w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1;
}