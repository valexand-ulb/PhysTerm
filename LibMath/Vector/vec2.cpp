//
// Created by alex on 5/01/24.
//

#include "vec2.h"

#include <cmath>
#include <iostream>

#include "../../Utilities/utilities.h"


vec2::vec2(float x, float y):tx{x},ty{y}, nx{x}, ny{y}{
}
vec2::vec2() {
}

vec2 vec2::normalize(float w, float h) {
    float normalized_x = (tx + 1.0f) / 2.0f;
    float normalized_y = 1.0f - (ty + 1.0f) / 2.0f;

    float term_x = std::round(normalized_x*(static_cast<float>(w)-1));
    float term_y = std::round(normalized_y*(static_cast<float>(h)-1));
    return vec2(term_x, term_y);
}
