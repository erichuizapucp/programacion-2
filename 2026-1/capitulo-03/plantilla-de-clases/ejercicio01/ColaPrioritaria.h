#ifndef COLAPRIORITARIA_H
#define COLAPRIORITARIA_H

#include "Cola.h"
#include "Pedido.h"

template <typename T>
class ColaPrioritaria : public Cola<T> {
public:
    ColaPrioritaria() = default;
    ColaPrioritaria(const ColaPrioritaria& orig);
    
    void encolar(T*) override;
    
    ~ColaPrioritaria() override = default;
};

template <typename T>
ColaPrioritaria<T>::ColaPrioritaria(const ColaPrioritaria<T>& orig) : Cola<T>(orig) {
}

template <typename T>
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

