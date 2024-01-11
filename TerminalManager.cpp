//
// Created by alex on 5/01/24.
//

#include "TerminalManager.h"
#include <cmath>
#include <iostream>
#include <sys/ioctl.h>
#include <vector>

#include "Utilities/utilities.h"

class Triangle3D;

TerminalManager::TerminalManager() {
    // get terminal size
    utilities::setSize(&width, &height);
    draw_buffer.resize(width*height, VOID_CHAR);
}

TerminalManager::~TerminalManager() {
    delete instance;
}


TerminalManager* TerminalManager::getInstance() {
    if (! instance) {
        instance = new TerminalManager();
    }
    return instance;
}

void TerminalManager::drawPixel(int x, int y, char c) {
    if (x >= 0 && x <= width && y >= 0 && y <=  height)
        draw_buffer.at(y*width+x) = c;
}

void TerminalManager::drawPixel(const vec2& v, const char c) {
    draw_buffer[static_cast<int>(v.y())*width+static_cast<int>(v.x())] = c;
}

void TerminalManager::drawTriangle(const Triangle2D& t, char c) {
    float x_min, x_max, y_min, y_max;
    basicFunction::min_of_triangle(t, x_min, y_min);
    basicFunction::max_of_triangle(t, x_max, y_max);
    //std::cout << "x_min: " << x_min << " x_max: " << x_max << " y_min: " << y_min << " y_max: " << y_max << std::endl;
    for (unsigned i=x_min; i<=x_max; i++) {
        if ( i < width && i >= 0) {
            for (unsigned j=y_min; j<=y_max; j++) {
                if (j >= 0 && j < height) {
                    vec2 v = vec2(i,j);
                    if (basicFunction::isPointInTriangle(v, t)) {
                        drawPixel(v, c);
                    }
                }
            }
        }
    }
}

void TerminalManager::drawMesh(const std::vector<Triangle3D>& mesh, const Camera &cam, char c) {
    for (const Triangle3D& t : mesh) {
        //std::cout << t.translation(cam.getPosition()*-1).rotateY(cam.getYaw()).rotateX() << std::endl;
        drawTriangle(
            t.translation(cam.getPosition() * -1)
            .rotateY(cam.getYaw())
            .rotateX(cam.getPitch())
            .projection(cam.getFocalLength())
            .normalize(width, height),
            c);
    }
}

void TerminalManager::render()const{
    std::string s="\e[?25l";
    //std::string s;
    for (unsigned int i = 0; i < draw_buffer.size(); i++) {
        if (i % width == 0 && i != 0) {
            s += "\n";
        }
        s += draw_buffer[i];
    }
    std::cout << s;
}

void TerminalManager::clear() {
    for (char & i : draw_buffer) {
        i = VOID_CHAR;
    }
    std::cout.flush();
}

TerminalManager* TerminalManager::instance = nullptr;

