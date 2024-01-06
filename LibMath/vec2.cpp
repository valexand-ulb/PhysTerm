//
// Created by alex on 5/01/24.
//

#include "../constant.h"
#include "vec2.h"

#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>

vec2::vec2(float x, float y):x{x},y{y} {
    setSize();
    normalize();
    //std::cout << "x: " << this->x << " y: " << this->y << std::endl;
}
vec2::vec2() {
    setSize();
    normalize();
}


void vec2::setSize() {
    struct winsize window;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
    w = window.ws_col-1;
    h = window.ws_row-1;
    if (w <= 0 || h <= 0) {
        w = DEFAULT_WIDTH-1;
        h = DEFAULT_HEIGHT-1;
    }
}



void vec2::normalize() {
    float normalized_x = 1.0f - (x + 1.0f) / 2.0f;
    float normalized_y = 1.0f - (y + 1.0f) / 2.0f;

    x = normalized_x*(static_cast<float>(w));
    y = normalized_y*(static_cast<float>(h));

    std::cout<< "x: " << x << " y: " << y << std::endl;
}