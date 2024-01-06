//
// Created by alex on 5/01/24.
//

#ifndef VEC2_H
#define VEC2_H

class vec2 {
private:
    float x,y;
    int w, h;

public:
    vec2(float x, float y);
    vec2();

    float X()const{return x;}
    float Y()const{return y;}

    vec2 operator+(const vec2& v) const{return vec2(x+v.x, y+v.y);}
    vec2 operator-(const vec2& v) const{return vec2(x-v.x, y-v.y);}
    vec2 operator*(const float& f) const{return vec2(x*f, y*f);}
    vec2 operator/(const float& f) const{return vec2(x/f, y/f);}

    void normalize();
};



#endif //VEC2_H
