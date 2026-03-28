//
// Created by Eric Huiza on 3/27/26.
//
#include "funciones.h"

#include <__chrono/literals.h>

Cliente& operator++(Cliente& cliente) {
    ++cliente.edad;
    return cliente;
}

Cliente& operator++(Cliente& cliente, int) {
    cliente.edad++;
    return cliente;
}

Cliente& operator--(Cliente& cliente) {
    --cliente.edad;
    return cliente;
}

Cliente& operator--(Cliente& cliente, int) {
    cliente.edad--;
    return cliente;
}

Pedido& operator+(Pedido& p1, Pedido& p2) {
    Pedido p3 = { p1.dni, p1.total + p2.total };
    return p3;
}

ostream& operator<<(ostream& os, Cliente& cliente) {
    os << "Datos del Cliente" << endl;
    os << "DNI: " << cliente.dni << endl;
    os << "Edad: " << cliente.edad << endl;
    return os;
}

ostream& operator<<(ostream& os, Pedido& pedido) {
    os << "Datos del Pedido" << endl;
    os << "DNI: " << pedido.dni << endl;
    os << "Total: " << pedido.total << endl;
    return os;
}