#include <iostream>
#include <unistd.h>

#include "TerminalManager.h"

int main() {
    TerminalManager *tm = TerminalManager::getInstance();
    float t=0;
    //std::cout << "width :" << tm->getWidth() << " heigth: "  << tm->getHeight() << std::endl;
    while (true) {
        Triangle t1 = Triangle({0.0f,0.0f},{0.5f+t,0.5f},{-0.5f,0.5f+t});
        tm->drawTriangle(t1, 'x');
        tm->render();
        tm->clear();
        t+= 0.01;
        if (t>1) t=0;
    }
    return 0;
}
