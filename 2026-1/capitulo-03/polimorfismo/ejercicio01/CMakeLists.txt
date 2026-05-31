cmake_minimum_required(VERSION 4.2)
project(ejercicio01)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejercicio01 main.cpp
        Persona.cpp
        Persona.h
        Alumno.cpp
        Alumno.h
        Profesor.cpp
        Profesor.h
        AlumnoRegular.cpp
        AlumnoRegular.h
        AlumnoIntercambio.cpp
        AlumnoIntercambio.h
        funciones.h
        funciones.cpp)
