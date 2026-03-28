//
// Created by Eric Huiza on 3/27/26.
//

#ifndef EJERCICIO04_FUNCIONES_H
#define EJERCICIO04_FUNCIONES_H

#include "estructuras.h"
#include <iostream>

using namespace std;

Cliente& operator++(Cliente&);
Cliente& operator++(Cliente&, int);

Cliente& operator--(Cliente&);
Cliente& operator--(Cliente&, int);

Pedido& operator+(Pedido&, Pedido&);

ostream& operator<<(ostream&, Cliente&);
ostream& operator<<(ostream&, Pedido&);

#endif //EJERCICIO04_FUNCIONES_H
