//
// Created by alex on 5/01/24.
//

#include "basicFunction.h"


bool basicFunction::isPointInTriangle(const vec2& v, const Triangle& t) {
    float d1 = sign(v, t.P1(), t.P2());
    float d2 = sign(v, t.P2(), t.P3());
    float d3 = sign(v, t.P3(), t.P1());

    bool hasneg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool haspos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return ! (hasneg && haspos);
}

float basicFunction::sign(const vec2& p1, const vec2& p2, const vec2& p3) {
    return (p1.X() - p3.X()) * (p2.Y() - p3.Y()) - (p2.X() - p3.X()) * (p1.Y() - p3.Y());
}

