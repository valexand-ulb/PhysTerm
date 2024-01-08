#include <iostream>
#include <unistd.h>
#include <chrono>

#include "TerminalManager.h"
#include "LibMath/Triangle/Triangle3D.h"

int main() {
    TerminalManager *tm = TerminalManager::getInstance();
    float t=0;
    //std::cout << "width :" << tm->getWidth() << " heigth: "  << tm->getHeight() << std::endl;

    while (t <0.001) {
        auto start = std::chrono::high_resolution_clock::now();
        Triangle2D t1 = Triangle2D({0.0f,0.0f},{0.5f,0.5f},{-0.5f,0.5f});
        Triangle3D t2 = Triangle3D({0.0f,0.0f,0.0f}, {0.5f,0.5f,0.0f}, {-0.5f,0.5f,0.0f});
        std::cout << t2 << std::endl;

        tm->drawTriangle(t2.projection().normalize(), 'x');
        //tm->drawTriangle(t1.normalize(), 'x');
        //tm->render();
        //tm->clear();
        t+= 0.01;
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
        //std::cout << "\nframe time: " << duration.count() << "ms";
        usleep(100000);
    }
    return 0;
}
