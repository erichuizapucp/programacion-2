cmake_minimum_required(VERSION 4.0)
project(ejercicio01)

set(CMAKE_CXX_STANDARD 20)

add_executable(ejercicio01 main.cpp
        Cliente.cpp
        Mesero.cpp
        Pedido.cpp
        PedidoPrioritario.cpp
        PedidoRegular.cpp
        Persona.cpp
        Registro.cpp
        Restaurante.cpp
        PedidoRegular.cpp
        Pila.h)
