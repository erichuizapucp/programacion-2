cmake_minimum_required(VERSION 4.2)
project(ejercicio01)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejercicio01 main.cpp
        funciones.cpp
        Clinica.cpp
        Clinica.h
        Paciente.cpp
        Paciente.h
        Doctor.cpp
        Doctor.h
        Cita.cpp
        Cita.h)
