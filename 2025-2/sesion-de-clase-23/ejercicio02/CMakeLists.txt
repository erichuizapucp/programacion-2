cmake_minimum_required(VERSION 4.0)
project(ejercicio02)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejercicio02 main.cpp
        AutoridadTransporte.cpp
        Conductor.cpp
        Infraccion.cpp
        Licencia.cpp
        Registro.cpp
        Vehiculo.cpp)
