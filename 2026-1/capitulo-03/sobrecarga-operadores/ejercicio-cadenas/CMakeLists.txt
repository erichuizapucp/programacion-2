cmake_minimum_required(VERSION 4.2)
project(ejercicio_cadenas)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejercicio_cadenas main.cpp
        Cadena.cpp
        Cadena.h
        ManejadorCadenas.cpp
        ManejadorCadenas.h)
