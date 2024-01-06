#include <iostream>

#include "TerminalManager.h"

int main() {
    TerminalManager *tm = TerminalManager::getInstance();
    float t=0;
    Triangle tri = Triangle(vec2(-0.5,-0.5), vec2(-0.5,0.5), vec2(0.5,0.5));
    //std::cout << "width :" << tm->getWidth() << " heigth: "  << tm->getHeight() << std::endl;
    tm->drawPixel({-1,-1},'0');
    tm->drawPixel({-1,1},'1');
    tm->drawPixel({1,-1},'2');
    tm->drawPixel({1,1},'3');
    tm->drawTriangle(tri, 'X');

    tm->drawPixel({0.5,0.5}, 'X');
    //tm->render();
    return 0;
}
