//
// Created by alex on 8/01/24.
//

#ifndef VEC3_H
#define VEC3_H
#include "vec2.h"


class vec3 {
private:
    float tx,ty,tz;

public:

    vec3(float x, float y, float z): tx{x}, ty{y}, tz{z} {};

    float x()const{return tx;}
    float y()const{return ty;}
    float z()const{return tz;}

    vec3 operator+(const vec3& v) const{return vec3(tx+v.tx, ty+v.ty, tz+v.tz);}
    vec3 operator-(const vec3& v) const{return vec3(tx-v.tx, ty-v.ty, tz-v.tz);}
    vec3 operator*(const float& f) const{return vec3(tx*f, ty*f, tz*f);}
    vec3 operator/(const float& f) const{return vec3(tx/f, ty/f, tz/f);}
    vec3 operator+=(const vec3& v){tx+=v.tx; ty+=v.ty; tz+=v.tz; return *this;}

    friend std::ostream& operator<<(std::ostream& os, const vec3& v){return os << "(" << v.tx << ", " << v.ty << ", " << v.tz << ")";}


    vec2 project() const{return vec2(tx,ty)/tz;}
    void rotationX(float pitch);
    void rotationY(float yaw);
};




#endif //VEC3_H
