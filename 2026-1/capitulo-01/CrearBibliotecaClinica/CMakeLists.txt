cmake_minimum_required(VERSION 4.2)
project(CrearBibliotecaClinica)

set(CMAKE_CXX_STANDARD 20)

add_library(Clinica STATIC MisBibliotecas/funciones.cpp)

add_executable(CrearBibliotecaClinica main.cpp)

target_link_libraries(CrearBibliotecaClinica Clinica)