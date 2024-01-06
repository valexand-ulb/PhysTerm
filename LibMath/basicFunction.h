//
// Created by alex on 5/01/24.
//

#ifndef BASICFUNCTION_H
#define BASICFUNCTION_H
#include "vec2.h"
#include "Triangle.h"


class basicFunction {
public:
    static bool isPointInTriangle(const vec2& v, const Triangle& t);
    static float sign(const vec2& p1, const vec2& p2, const vec2& tp3);

};



#endif //BASICFUNCTION_H
