/* 
 * File:   funciones.h
 * Author: erichuiza
 *
 * Created on March 28, 2025, 5:01 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include "estructuras.h"
#include <iomanip>

using namespace std;

Cliente& operator+=(Cliente&, Pedido&);
Pedido& operator+=(Pedido&, Producto&);

template<typename T>
bool operator==(T& a, T& b);

template<typename T>
bool operator==(T& a, T& b) {
    return a.codigo == b.codigo;
}

template<typename T>
bool operator!=(T& a, T& b);

template<typename T>
bool operator!=(T& a, T& b) {
    return a.codigo != b.codigo;
}

ostream& operator<<(ostream&, const Cliente&);

#endif /* FUNCIONES_H */

