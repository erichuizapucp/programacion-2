cmake_minimum_required(VERSION 4.0)
project(sesion_de_clase_20)

set(CMAKE_CXX_STANDARD 20)

add_executable(sesion_de_clase_20 main.cpp
        Cliente.cpp
        Cola.cpp
        ColaPrioritaria.cpp
        Lista.cpp
        Mesero.cpp
        Nodo.cpp
        Pedido.cpp
        PedidoPrioritario.cpp
        PedidoRegular.cpp
        Persona.cpp
        Registro.cpp
        Restaurante.cpp)
