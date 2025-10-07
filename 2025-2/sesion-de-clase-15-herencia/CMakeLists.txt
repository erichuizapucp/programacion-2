cmake_minimum_required(VERSION 4.0)
project(sesion_de_clase_15_herencia)

set(CMAKE_CXX_STANDARD 20)

add_executable(sesion_de_clase_15_herencia main.cpp
        Registro.cpp
        Registro.h
        Usuario.cpp
        Usuario.h
        Publicacion.cpp
        Publicacion.h
        UsuarioEstandard.cpp
        UsuarioEstandard.h
        UsuarioVerificado.cpp
        UsuarioVerificado.h
        Foto.cpp
        Foto.h
        Video.cpp
        Video.h
        Historia.cpp
        Historia.h
        Album.cpp
        Album.h
        Reel.cpp
        Reel.h
)
