//
// Created by alex on 5/01/24.
//

#include "vec2.h"

#include <cmath>
#include <iostream>

#include "../Utilities/utilities.h"
#include "../constant.h"



vec2::vec2(float x, float y, bool normalized):tx{x},ty{y}, nx{x}, ny{y}{
    if (DEBUG) std::cout << "----------" << std::endl;
    utilities::setSize(&w, &h);
    if (DEBUG) std::cout << " x: " << this->tx << " y: " << this->ty << std::endl;
    if (normalized) normalize();
    if (DEBUG) std::cout << " x: " << this->tx << " y: " << this->ty << std::endl;
}
vec2::vec2() {
    utilities::setSize(&w, &h);
    normalize();
}

void vec2::normalize() {
    float normalized_x = (tx + 1.0f) / 2.0f;
    float normalized_y = 1.0f - (ty + 1.0f) / 2.0f;

    tx = std::round(normalized_x*(static_cast<float>(w)-1));
    ty = std::round(normalized_y*(static_cast<float>(h)-1));
}