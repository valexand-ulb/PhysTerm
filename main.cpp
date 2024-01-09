#include <iostream>
#include <unistd.h>
#include <chrono>

#include "TerminalManager.h"
#include "LibMath/Triangle/Triangle3D.h"
#include "Utilities/Debug.h"

int main() {
    TerminalManager *tm = TerminalManager::getInstance();
    float t=0;
    //std::cout << "width :" << tm->getWidth() << " heigth: "  << tm->getHeight() << std::endl;

    while (true) {
        Debug::printCorners();
        Triangle3D t1 = Triangle3D(vec3{0.0f,0.0f,1.0f}, vec3{0.5f,0.0f,1.0f}, vec3{0.0f,0.5f,1.0f});
        //t1.translate({0,0,2.0f});
        //t1.rotateY(t);
        //tm->drawTriangle(t1.projection().normalize(tm->getWidth(),tm->getHeight()), '@');
        tm->render();
        tm->clear();
        t+= 0.01;
        usleep(100);
    }
    return 0;
}
