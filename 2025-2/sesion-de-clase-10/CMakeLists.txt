cmake_minimum_required(VERSION 4.0)
project(sesion_de_clase_10)

set(CMAKE_CXX_STANDARD 20)

add_executable(sesion_de_clase_10 main.cpp
        tads/src/cola.cpp
        tads/src/lista.cpp
        tads/src/pila.cpp
        src/funciones.cpp)
