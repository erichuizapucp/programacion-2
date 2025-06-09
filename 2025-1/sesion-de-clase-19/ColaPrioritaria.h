/* 
 * File:   ColaPrioritaria.h
 * Author: erichuiza
 *
 * Created on June 4, 2025, 4:59 PM
 */

#ifndef COLAPRIORITARIA_H
#define COLAPRIORITARIA_H

#include "Cola.h"
#include "Pedido.h"

template<typename T>
class ColaPrioritaria : public Cola<T> {
public:
    void encolar(T*);
    virtual ~ColaPrioritaria<T>() = default;
};

template<typename T>
void ColaPrioritaria<T>::encolar(T* dato) {
    if (this->estaVacia() || 
            dato->getPrioridad() == 
            PedidoPrioridad::REGULAR) {
        this->lista.insertarUltimo(dato);
        return;
    }

    Nodo<T>* actual = this->lista.cabeza;
    Nodo<T>* anterior = nullptr;

    while (actual != nullptr && 
            actual->getDato()->getPrioridad() == 
            PedidoPrioridad::ALTA) {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    this->lista.insertar(anterior, dato);
}

#endif /* COLAPRIORITARIA_H */

