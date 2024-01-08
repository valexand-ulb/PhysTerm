//
// Created by alex on 8/01/24.
//

#include "Triangle2D.h"

Triangle2D Triangle2D::normalize() {
    return Triangle2D(p1.normalize(),p2.normalize(),p3.normalize());
}