#include <iostream>

#include "TerminalManager.h"

int main() {
    TerminalManager *tm = TerminalManager::getInstance();
    float t=0;
    //Triangle tri = Triangle(vec2(0.5,0.5), vec2(1,0.5), vec2(0.5,1));
    std::cout << "width :" << tm->getWidth() << " heigth: "  << tm->getHeight() << std::endl;;
    //tm->render();
    vec2{1,1};
    vec2{-1,-1};
    //std::cout << "width: " << tm->getWidth() << " height: " << tm->getHeight();
    return 0;
}
