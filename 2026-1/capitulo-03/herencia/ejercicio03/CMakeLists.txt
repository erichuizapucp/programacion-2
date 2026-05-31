cmake_minimum_required(VERSION 4.2)
project(ejercicio03)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejercicio03 main.cpp
        VehiculoMotorizado.cpp
        VehiculoHidrogeno.cpp
        VehiculoHibrido.cpp
        VehiculoElectrico.cpp
        VehiculoCombustion.cpp
        Carreta.cpp)
