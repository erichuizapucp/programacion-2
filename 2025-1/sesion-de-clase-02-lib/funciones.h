/* 
 * File:   funciones.h
 * Author: erichuiza
 *
 * Created on March 27, 2025, 9:52 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "estructuras.h"
#include <iostream>
#include <iomanip>

using namespace std;

Cliente& operator+=(Cliente&, Pedido&);
Pedido& operator+=(Pedido&, Producto&);

template<typename T>
bool operator==(T& a, T& b) {
    return a.codigo == b.codigo;
}

template<typename T>
bool operator!=(T& a, T& b) {
    return a.codigo != b.codigo;
}

ostream& operator<<(ostream&, Cliente&);

#endif /* FUNCIONES_H */
