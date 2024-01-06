//
// Created by alex on 5/01/24.
//

#ifndef TERMINALMANAGER_H
#define TERMINALMANAGER_H

#include <vector>

#include "constant.h"
#include "LibMath/Triangle.h"
#include "LibMath/basicFunction.h"

class TerminalManager {
private:
    static TerminalManager *instance;
    int width= DEFAULT_WIDTH;
    int height = DEFAULT_HEIGHT;
    std::vector<char> draw_buffer = std::vector(width*height, VOID_CHAR);

    TerminalManager();

public:
    static TerminalManager*getInstance();

    int getWidth() const {return width;}
    int getHeight() const {return height;}
    int getSize() const {return width*height;}

    void drawPixel(int x, int y, char c);
    void drawPixel(const vec2& v, char c);
    void drawTriangle(const Triangle &t, char c);

    void render()const;
    void clear();

    ~TerminalManager();
};



#endif //TERMINALMANAGER_H
