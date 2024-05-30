cmake_minimum_required(VERSION 3.27)

project(saod_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(STComplete STComplete.cpp
        SufTree.h SufTree.cpp Node.h Edge.cpp Edge.h)