cmake_minimum_required(VERSION 4.0)
project(UsaBibliotecaEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(UsaBibliotecaEstatica main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/RedSocial")
target_link_libraries(UsaBibliotecaEstatica PRIVATE RedSocial)
