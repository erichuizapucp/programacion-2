cmake_minimum_required(VERSION 4.0)
project(ejercicio01)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejercicio01 main.cpp
        estructuras.h
        funciones.cpp
        funciones.h
        qsort.h
        qsort.cpp)
