//
// Created by alex on 5/01/24.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vec2.h"


class Triangle {
private:
 vec2 p1, p2, p3;
 int w,h;

public:
 Triangle(const vec2 &p1, const vec2 &p2, const vec2 &p3): p1(p1), p2(p2), p3(p3) {}
 vec2 P1()const{return p1;}
 vec2 P2()const{return p2;}
 vec2 P3()const{return p3;}
};



#endif //TRIANGLE_H
