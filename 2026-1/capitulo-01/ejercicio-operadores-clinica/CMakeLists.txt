cmake_minimum_required(VERSION 4.2)
project(ejercicio_operadores_clinica)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejercicio_operadores_clinica main.cpp
        funciones.cpp
        enums.h
        funciones.h
        estructuras.h)
