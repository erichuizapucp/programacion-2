/* 
 * File:   Contador.cpp
 * Author: erichuiza
 * 
 * Created on November 22, 2024, 3:32 PM
 */

#include "Contador.h"

int Contador::cantidad = 0;

Contador::Contador() {
}

Contador::Contador(const Contador& orig) {
}

void Contador::incrementar() {
    cantidad++;
}

int Contador::getCantidad() {
    return cantidad;
}

Contador::~Contador() {
}

