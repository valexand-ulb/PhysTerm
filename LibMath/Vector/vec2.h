//
// Created by alex on 5/01/24.
//

#ifndef VEC2_H
#define VEC2_H
#include <ostream>

class vec2 {
private:
    float tx,ty;
    float nx, ny;

public:
    vec2(float x, float y);
    vec2();

    float x()const{return tx;}
    float y()const{return ty;}
    float normalized_x()const{return nx;}
    float normalized_y()const{return ny;}

    vec2 operator+(const vec2& v) const{return vec2(tx+v.tx, ty+v.ty);}
    vec2 operator-(const vec2& v) const{return vec2(tx-v.tx, ty-v.ty);}
    vec2 operator*(const float& f) const{return vec2(tx*f, ty*f);}
    vec2 operator/(const float& f) const{return vec2(tx/f, ty/f);}

    friend std::ostream& operator<<(std::ostream& os, const vec2& v){return os << "(" << v.tx<< ", " << v.ty << ")";}



    vec2 normalize(float w, float h);
};



#endif //VEC2_H
