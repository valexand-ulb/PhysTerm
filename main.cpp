#include <iostream>
#include <unistd.h>
#include <chrono>

#include "TerminalManager.h"
#include "LibMath/Triangle/Triangle3D.h"
#include "Utilities/Debug.h"



int main() {
    TerminalManager *tm = TerminalManager::getInstance();
    Camera cam{{0.0f,0.0f,-3.0f},0.0f,0.0f};
    float t=0;
    //std::cout << "width :" << tm->getWidth() << " heigth: "  << tm->getHeight() << std::endl;
    Triangle3D t1 = Triangle3D(vec3{-0.5f,-0.5f,0.0f}, vec3{0.0f,0.5f,0.0f}, vec3{0.5f,-0.5f,0.0f});
    std::vector<Triangle3D> mesh = {t1};

    while (true) {
        //Debug::printCorners();
        //std::cout << Triangle3D{t1.rotateY(t).translate({0.0f,0.0f,2.0f})} << std::endl;
        tm->drawTriangle(t1
            .rotateY(t)
            .translation({0.0f,0.0f,2.0f})
            .projection()
            .normalize(tm->getWidth(),tm->getHeight()),
            '@');
        //tm->drawMesh(mesh, cam, '@');
        tm->render();
        tm->clear();
        t+= 0.01;
        usleep(10000);
    }
    return 0;
}
