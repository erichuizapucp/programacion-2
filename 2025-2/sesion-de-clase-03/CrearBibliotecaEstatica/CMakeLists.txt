cmake_minimum_required(VERSION 4.0)
project(CrearBiblioteca)

set(CMAKE_CXX_STANDARD 20)

add_library(RedSocial STATIC RedSocial/funciones.cpp)

add_executable(CrearBiblioteca main.cpp)

target_link_libraries(CrearBiblioteca RedSocial)
