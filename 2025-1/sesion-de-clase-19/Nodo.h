/* 
 * File:   Nodo.h
 * Author: erichuiza
 *
 * Created on June 2, 2025, 2:24 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Pedido.h"
#include "Lista.h"

template <typename T>
class Lista;

template <typename T>
class Nodo {
private:
    T* dato;
    Nodo* siguiente;
public:
    T* getDato() const;
    void setDato(T*);
    Nodo<T>* getSiguiente() const;
    void setSiguiente(Nodo<T>*);
    
    friend class Lista<T>;
    
    virtual ~Nodo() = default;
};

template<typename T>
T* Nodo<T>::getDato() const {
    return dato;
}

template<typename T>
void Nodo<T>::setDato(T* dato) {
    this->dato = dato;
}

template<typename T>
Nodo<T>* Nodo<T>::getSiguiente() const {
    return siguiente;
}

template<typename T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente) {
    this->siguiente = siguiente;
}

#endif /* NODO_H */

