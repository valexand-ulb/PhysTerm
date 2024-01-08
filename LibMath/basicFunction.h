//
// Created by alex on 5/01/24.
//

#ifndef BASICFUNCTION_H
#define BASICFUNCTION_H
#include "Vector/vec2.h"
#include "Triangle/Triangle2D.h"


class basicFunction {
public:
    static bool isPointInTriangle(const vec2& v, const Triangle2D& t);
    static void min_of_triangle(const Triangle2D& t, float& x_min, float& y_min);
    static void max_of_triangle(const Triangle2D&t, float& x_max, float& y_max);

};



#endif //BASICFUNCTION_H
