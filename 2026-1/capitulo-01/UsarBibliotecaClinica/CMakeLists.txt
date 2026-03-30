cmake_minimum_required(VERSION 4.2)
project(UsarBibliotecaClinica)

set(CMAKE_CXX_STANDARD 20)

add_executable(UsarBibliotecaClinica main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/MisBibliotecas")

target_link_libraries(UsarBibliotecaClinica PRIVATE Clinica)