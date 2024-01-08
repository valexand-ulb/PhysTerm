//
// Created by alex on 5/01/24.
//

#include "basicFunction.h"

#include <cmath>


bool basicFunction::isPointInTriangle(const vec2& v, const Triangle2D& t) {
    float s1 = t.v3().y() - t.v1().y();
    float s2 = t.v3().x() - t.v1().x();
    float s3 = t.v2().y() - t.v1().y();
    float s4 = v.y() - t.v1().y();

    float w1 = (t.v1().x() * s1 + s4 * s2 - v.x() * s1) / (s3 * s2 - (t.v2().x() - t.v1().x()) * s1);
    float w2 = (s4 - w1 * s3) / s1;

    return w1 >= 0 && w2 >= 0 && (w1 + w2) <= 1;
}

void basicFunction::min_of_triangle(const Triangle2D& t, float& x_min, float& y_min) {
    x_min = std::round(
        std::min(
            t.v1().x(),
            std::min(t.v2().x(), t.v3().x())
            ));
    y_min = std::round(
        std::min(
            t.v1().y(),
            std::min(t.v2().y(), t.v3().y())));
}

void basicFunction::max_of_triangle(const Triangle2D& t, float& x_max, float& y_max) {
    x_max = std::round(
        std::max(
            t.v1().x(),
            std::max(t.v2().x(), t.v3().x())));
    y_max = std::round(
        std::max(
            t.v1().y(),
            std::max(t.v2().y(), t.v3().y())));
}

