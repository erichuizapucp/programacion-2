cmake_minimum_required(VERSION 4.2)
project(CreaBibliotecaEstatica)

set(CMAKE_CXX_STANDARD 20)

add_library(Clinica STATIC MisBibliotecas/funciones.cpp)

add_executable(CreaBibliotecaEstatica main.cpp)

target_link_libraries(CreaBibliotecaEstatica Clinica)