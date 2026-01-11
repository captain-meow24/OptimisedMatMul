cmake_minimum_required(VERSION 3.31)
project(OptimisedMatMul)

set(CMAKE_CXX_STANDARD 20)

add_executable(OptimisedMatMul main.cpp
        BaselineMatMul.cpp
        BaselineMatMul.h
        OptimisedMatMul.h
        OptimisedMatMul.cpp)
