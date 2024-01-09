//
// Created by alex on 8/01/24.
//

#include "Triangle2D.h"

Triangle2D Triangle2D::normalize(float w, float h) {
    return Triangle2D(p1.normalize(w,h),p2.normalize(w,h),p3.normalize(w,h));
}