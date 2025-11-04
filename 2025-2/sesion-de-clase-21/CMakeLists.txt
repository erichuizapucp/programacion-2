cmake_minimum_required(VERSION 4.0)
project(sesion_de_clase_21)

set(CMAKE_CXX_STANDARD 20)

add_executable(sesion_de_clase_21 main.cpp
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
