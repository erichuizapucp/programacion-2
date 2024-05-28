#include "cola.h"

Cola::Cola() {
    frente = nullptr;
    fondo = nullptr;
}

void Cola::encola(void* dato) {
    Nodo* nuevoNodo = new Nodo(dato);
    
    if (colaVacia()) {    
        frente = nuevoNodo;
        fondo = nuevoNodo;
    }
    else {
        if (fondo != nullptr) {
            fondo->siguiente = nuevoNodo;
        }
        fondo = nuevoNodo;
    }
}

void* Cola::desencola() {
    if (colaVacia()) {
        return nullptr;
    }
    
    void* valor = frente->dato;
    Nodo* temp = frente;
    frente = frente->siguiente;
    
    if (frente == nullptr) {
        fondo = nullptr;
    }
    
    delete temp;
    
    return valor;
}

bool Cola::colaVacia() {
    return frente == nullptr;
}

Nodo* Cola::getFrente() {
    return frente;
}

Nodo* Cola::getFondo() {
    return fondo;
}

Cola::~Cola() {
    while (!colaVacia()) {
        Nodo* temp = frente;
        frente = frente->siguiente;
        delete temp;
    }
}