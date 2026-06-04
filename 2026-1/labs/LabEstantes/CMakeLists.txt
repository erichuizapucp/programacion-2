cmake_minimum_required(VERSION 4.2)
project(LabEstantes)

set(CMAKE_CXX_STANDARD 20)

add_executable(LabEstantes
        main.cpp
        funciones.cpp
        Libro.cpp
        Enciclopedia.cpp
        Novela.cpp
        Espacio.cpp
        Estante.cpp
        EstanteVertical.cpp
        EstanteHorizontal.cpp
        Biblioteca.cpp)
