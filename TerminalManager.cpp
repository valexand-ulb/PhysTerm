//
// Created by alex on 5/01/24.
//

#include "TerminalManager.h"
#include <cmath>
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <vector>

TerminalManager::TerminalManager() {
    // get terminal size
    setSize();
    buffer = new char[width*height];
    draw_buffer.resize(width*height, VOID_CHAR);
}

TerminalManager::~TerminalManager() {
    delete[] buffer;
    delete instance;
}


TerminalManager* TerminalManager::getInstance() {
    if (! instance) {
        instance = new TerminalManager();
    }
    return instance;
}

void TerminalManager::setSize() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    width = w.ws_col;
    height = w.ws_row;
    if (width <= 0 || height <= 0) {
        width = DEFAULT_WIDTH;
        height = DEFAULT_HEIGHT;
    }
}

void TerminalManager::drawPixel(int x, int y, char c) {
    if (x >= 0 && x <= width && y >= 0 && y <=  height);
        //buffer[y*width+x] = c;
        draw_buffer.at(y*width+x) = c;
}

void TerminalManager::drawPixel(const vec2& v, const char c) {
    draw_buffer[static_cast<int>(v.Y())*width+static_cast<int>(v.X())] = c;
}

void TerminalManager::drawTriangle(const Triangle& t, char c) {

    const int xmin = static_cast<int>(std::round(std::min(t.P1().X(), std::min(t.P2().X(), t.P3().X()))));
    const int xmax = static_cast<int>(std::round(std::max(t.P1().X(), std::max(t.P2().X(), t.P3().X()))));
    const int ymin = static_cast<int>(std::round(std::min(t.P1().Y(), std::min(t.P2().Y(), t.P3().Y()))));
    const int ymax = static_cast<int>(std::round(std::max(t.P1().Y(), std::max(t.P2().Y(), t.P3().Y()))));

    for (int y = ymin; y <= ymax; y++) {
        for (int x = xmin; x <= xmax; x++) {
            vec2 pos(x,y);
            if (basicFunction::isPointInTriangle(pos, t)){
                drawPixel(pos, c);
            }
        }
    }
}

void TerminalManager::render()const{
    //std::string s="\e[?25l";
    std::string s;
    for (char c : draw_buffer) {
        s += c;
    }
    std::cout << s;
    s = "";
}

void TerminalManager::clear() {
    for (char & i : draw_buffer) {
        i = VOID_CHAR;
    }
    for (unsigned int i = 0; i <= sizeof(buffer)/sizeof(char); ++i) {
        i = VOID_CHAR;
    }
}




TerminalManager* TerminalManager::instance = nullptr;

