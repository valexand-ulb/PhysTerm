//
// Created by alex on 8/01/24.
//

#ifndef TRIANGLE2D_H
#define TRIANGLE2D_H

#include "../Vector/vec2.h"


class Triangle2D {
private:
    vec2 p1, p2, p3;
    int w,h;

public:
    Triangle2D(const vec2 &p1, const vec2 &p2, const vec2 &p3): p1(p1), p2(p2), p3(p3) {}
    vec2 v1()const{return p1;}
    vec2 v2()const{return p2;}
    vec2 v3()const{return p3;}


    friend std::ostream& operator<<(std::ostream& os, const Triangle2D &t){return os <<"p1" << t.p1 << ", p2" << t.p2 << ", p3" << t.p3 << std::endl;}
    Triangle2D normalize();

};
#endif //TRIANGLE2D_H