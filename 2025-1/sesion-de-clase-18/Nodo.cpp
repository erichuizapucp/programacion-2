/* 
 * File:   Nodo.cpp
 * Author: erichuiza
 * 
 * Created on June 2, 2025, 2:24 PM
 */

#include "Nodo.h"

Nodo::Nodo() {
}

Nodo::Nodo(const Nodo& orig) {
}

Pedido* Nodo::getPedido() const {
    return pedido;
}

void Nodo::setPedido(Pedido* pedido) {
    this->pedido = pedido;
}

Nodo* Nodo::getSiguiente() const {
    return siguiente;
}

void Nodo::setSiguiente(Nodo* siguiente) {
    this->siguiente = siguiente;
}

Nodo::~Nodo() {
}

