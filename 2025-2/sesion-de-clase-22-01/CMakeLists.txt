cmake_minimum_required(VERSION 4.0)
project(sesion_de_clase_22_01)

set(CMAKE_CXX_STANDARD 20)

add_executable(sesion_de_clase_22_01 main.cpp
        Registro.cpp
        Registro.h
        Alumno.cpp
        Alumno.h
        Universidad.cpp
        Universidad.h
        AlumnoInfo.cpp
        AlumnoInfo.h
        AlumnoRegular.cpp
        AlumnoRegular.h
        AlumnoIntercambio.cpp
        AlumnoIntercambio.h
)
