//
// Created by alex on 5/01/24.
//

#include "TerminalManager.h"
#include <cmath>
#include <iostream>
#include <sys/ioctl.h>
#include <vector>

#include "Utilities/utilities.h"

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
        //buffer[y*width+x] = c;
        draw_buffer.at(y*width+x) = c;
}

void TerminalManager::drawPixel(const vec2& v, const char c) {
    draw_buffer[static_cast<int>(v.y())*width+static_cast<int>(v.x())] = c;
}

void TerminalManager::drawTriangle(const Triangle& t, char c) {
    for (unsigned i=0; i<=width; i++) {
        for (unsigned j=0; j<=height; j++) {
            vec2 v = vec2(i,j,0);
            if (basicFunction::isPointInTriangle(v, t)) {
                drawPixel(v, c);
            }
        }
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
}

TerminalManager* TerminalManager::instance = nullptr;

