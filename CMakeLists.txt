cmake_minimum_required(VERSION 3.27)
project(PhysicTerm)

set(CMAKE_CXX_STANDARD 23)

add_executable(PhysicTerm main.cpp
        LibMath/vec2.cpp
        LibMath/vec2.h
        LibMath/Triangle.cpp
        LibMath/Triangle.h
        TerminalManager.cpp
        TerminalManager.h
        LibMath/basicFunction.cpp
        LibMath/basicFunction.h
        constant.h
        Utilities/utilites.cpp
        Utilities/utilities.h)
