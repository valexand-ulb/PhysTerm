//
// Created by alex on 5/01/24.
//

#include "vec2.h"

#include <cmath>

#include "../Utilities/utilities.h"

#include <iostream>

vec2::vec2(float x, float y):x{x},y{y} {
    std::cout << "----------" << std::endl;
    utilities::setSize(&w, &h);
    std::cout << " x: " << this->x << " y: " << this->y << std::endl;
    normalize();
    std::cout << " x: " << this->x << " y: " << this->y << std::endl;
}
vec2::vec2() {
    utilities::setSize(&w, &h);
    normalize();
}

void vec2::normalize() {
    float normalized_x = (1 * x + 1.0f) / 2.0f;
    float normalized_y = (y + 1.0f) / 2.0f;

    x = std::round(normalized_x*(static_cast<float>(w)-1));
    y = std::round(normalized_y*(static_cast<float>(h)-1));
}