#ifndef COLA_H
#define COLA_H

#include <iostream>
#include "Lista.h"

using namespace std;

template <typename T>
class Cola {
protected:
    Lista<T> lista;
public:
    Cola() = default;
    
    virtual void encolar(T*);
    virtual T* desencolar();
    bool estaVacia() const;
    virtual void imprimir(ostream&);
    
    virtual ~Cola() = default;
};

template <typename T>
void Cola<T>::encolar(T* dato) {
    this->lista.insertarUltimo(dato);
}

template <typename T>
T* Cola<T>::desencolar() {
    T* primero;
    if (this->lista.removerPrimero(primero)) {
        return primero;
    }

    return nullptr;
}

template <typename T>
void Cola<T>::imprimir(ostream& os) {
    this->lista.imprimir(os);
}

template <typename T>
bool Cola<T>::estaVacia() const {
    return this->lista.estaVacia();
}

#endif /* COLA_H */

