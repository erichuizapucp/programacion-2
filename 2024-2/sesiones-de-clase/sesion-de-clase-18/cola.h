/* 
 * File:   cola.h
 * Author: erichuiza
 *
 * Created on May 27, 2024, 12:07 PM
 */

#ifndef COLA_H
#define COLA_H

#include "nodo.h"

template <typename T>
class Cola {
private:
    Nodo<T>* frente;
    Nodo<T>* fondo;
public:
    Cola();
    void encola(T);
    bool desencola(T&);
    bool colaVacia();
    
    ~Cola();
};

template <typename T>
Cola<T>::Cola() {
    frente = nullptr;
    fondo = nullptr;
}

template <typename T>
void Cola<T>::encola(T dato) {
    Nodo<T>* nuevoNodo = new Nodo<T>(dato);
    
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

template <typename T>
bool Cola<T>::desencola(T& v) {
    if (colaVacia()) {
        return false;
    }
    
    T valor = frente->dato;
    Nodo<T>* temp = frente;
    frente = frente->siguiente;
    
    if (frente == nullptr) {
        fondo = nullptr;
    }
    
    delete temp;
    
    v = valor;
    return true;
}

template <typename T>
bool Cola<T>::colaVacia() {
    return frente == nullptr;
}

template <typename T>
Cola<T>::~Cola() {
    while (!colaVacia()) {
        Nodo<T>* temp = frente;
        frente = frente->siguiente;
        delete temp;
    }
}

#endif /* COLA_H */

