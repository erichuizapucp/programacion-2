cmake_minimum_required(VERSION 4.0)
project(sesion_de_clase_16)

set(CMAKE_CXX_STANDARD 20)

add_executable(sesion_de_clase_16 main.cpp
        RedSocial.cpp
        RedSocial.h
        Usuario.cpp
        Usuario.h
        Filtros/FiltroEdad.cpp
        Filtros/FiltroEdad.h
        Comparadores/CompararEdad.cpp
        Comparadores/CompararEdad.h
        Publicacion.cpp
        Publicacion.h
        UsuarioEstandard.cpp
        UsuarioEstandard.h
        UsuarioVerificado.cpp
        UsuarioVerificado.h
        Registro.cpp
        Registro.h)
