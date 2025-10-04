cmake_minimum_required(VERSION 4.0)
project(sesion_de_clase_14)

set(CMAKE_CXX_STANDARD 20)

add_executable(sesion_de_clase_14 main.cpp
        RedSocial.cpp
        RedSocial.h
        Usuario.cpp
        Usuario.h
        Filtros/FiltroEdad.cpp
        Filtros/FiltroEdad.h
        Comparadores/CompararEdad.cpp
        Comparadores/CompararEdad.h)
