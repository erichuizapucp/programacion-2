/* 
 * File:   Lista.cpp
 * Author: erichuiza
 * 
 * Created on June 2, 2025, 2:25 PM
 */

#include "Lista.h"
#include "Nodo.h"

Lista::Lista() {
    this->cabeza = nullptr;
    this->cola = nullptr;
    this->longitud = 0;
}

void Lista::insertarPrimero(Pedido* pedido) {
    this->insertar(nullptr, pedido);
}

void Lista::insertarUltimo(Pedido* pedido) {
    this->insertar(this->cola, pedido);
}

void Lista::insertar(Nodo* nodo, Pedido* pedido) {
    Nodo* nuevo = new Nodo;
    nuevo->pedido = pedido;
    nuevo->siguiente = nullptr;

    if (nodo == nullptr) {
        nuevo->siguiente = this->cabeza;
        this->cabeza = nuevo;

        if (this->estaVacia()) {
            this->cola = nuevo;
        }
    } else {
        nuevo->siguiente = nodo->siguiente;
        nodo->siguiente = nuevo;

        if (nodo == this->cola) {
            this->cola = nuevo;
        }
    }

    this->longitud++;
}

bool Lista::removerPrimero(Pedido*& pedido) {
    return this->remover(nullptr, pedido);
}

bool Lista::removerUltimo(Pedido*& pedido) {
    return this->remover(this->cola, pedido);
}

bool Lista::remover(Nodo* nodo, Pedido*& pedido) {
    if (this->estaVacia()) {
        return false;
    }
    
    Nodo* anterior;
    
    if (nodo == nullptr) {
        pedido = this->cabeza->pedido;
        anterior = this->cabeza;
        this->cabeza = this->cabeza->siguiente;
        
        if (this->longitud == 1) {
            this->cola = nullptr;
        }
    }
    else {
        if (nodo->siguiente == nullptr) {
            return false;
        }
        pedido = nodo->siguiente->pedido;
        anterior = nodo->siguiente;
        nodo->siguiente = nodo->siguiente->siguiente;
        
        if (nodo->siguiente == nullptr) {
            this->cola = nodo;
        }
    }
    
    delete anterior;
    this->longitud--;
    
    return true;
}

bool Lista::estaVacia() const {
    return this->longitud == 0;
}

void Lista::imprimir(ostream& os) {
    const Nodo* nodo = this->cabeza;
    
    while (nodo != nullptr) {
        os << *nodo->pedido;
        nodo = nodo->siguiente;
    }
}

Lista::~Lista() {
    while (this->longitud > 0) {
        Pedido* pedido;
        if (remover(nullptr, pedido)) {
            delete pedido;
        }
    }
}
