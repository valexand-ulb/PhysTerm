#include <iostream>
#include <unistd.h>

#include "TerminalManager.h"

int main() {
    TerminalManager *tm = TerminalManager::getInstance();
    float t=0;
    //Triangle tri = Triangle(vec2(0.5,0.5), vec2(1,0.5), vec2(0.5,1));
    //std::cout << "width :" << tm->getWidth() << " heigth: "  << tm->getHeight() << std::endl;;
    tm->drawPixel(vec2{1,1},'a');
    tm->drawPixel(vec2{-1,-1},'b');
    tm->drawPixel({-1,1},'c');
    tm->drawPixel({1,-1},'d');
    tm->render();

    //std::cout << "width: " << tm->getWidth() << " height: " << tm->getHeight() << std::endl;
    return 0;
}
