cmake_minimum_required(VERSION 3.27)
project(PhysicTerm)

set(CMAKE_CXX_STANDARD 23)

add_executable(PhysicTerm main.cpp
        LibMath/Vector/vec2.cpp
        LibMath/Vector/vec2.h
        TerminalManager.cpp
        TerminalManager.h
        LibMath/basicFunction.cpp
        LibMath/basicFunction.h
        constant.h
        Utilities/utilites.cpp
        Utilities/utilities.h
        LibMath/Vector/vec3.cpp
        LibMath/Vector/vec3.h
        LibMath/Triangle/Triangle2D.cpp
        LibMath/Triangle/Triangle2D.h
        LibMath/Triangle/Triangle3D.cpp
        LibMath/Triangle/Triangle3D.h
)
