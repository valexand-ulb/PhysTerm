//
// Created by alex on 5/01/24.
//

#ifndef VEC2_H
#define VEC2_H

class vec2 {
private:
    float tx,ty;
    float nx, ny;

    int w, h;

public:
    vec2(float x, float y, bool normalized=true);
    vec2();

    float x()const{return tx;}
    float y()const{return ty;}
    float normalized_x()const{return nx;}
    float normalized_y()const{return ny;}

    vec2 operator+(const vec2& v) const{return vec2(tx+v.tx, ty+v.ty);}
    vec2 operator-(const vec2& v) const{return vec2(tx-v.tx, ty-v.ty);}
    vec2 operator*(const float& f) const{return vec2(tx*f, ty*f);}
    vec2 operator/(const float& f) const{return vec2(tx/f, ty/f);}

    void normalize();
};



#endif //VEC2_H
