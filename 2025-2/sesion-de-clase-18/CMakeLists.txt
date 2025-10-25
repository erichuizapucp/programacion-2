cmake_minimum_required(VERSION 4.0)
project(sesion_de_clase_18)

set(CMAKE_CXX_STANDARD 20)

add_executable(sesion_de_clase_18 main.cpp
        Registro.cpp
        Registro.h
        Alumno.cpp
        Alumno.h
        AlumnoIntercambio.cpp
        AlumnoIntercambio.h
        AlumnoRegular.cpp
        AlumnoRegular.h)
