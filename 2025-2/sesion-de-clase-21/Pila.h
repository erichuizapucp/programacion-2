//
// Created by Eric Huiza on 11/3/25.
//

#ifndef SESION_DE_CLASE_21_PILA_H
#define SESION_DE_CLASE_21_PILA_H

#include <iostream>
#include "Lista.h"

template <typename T>
class Pila {
protected:
    Lista<T> lista;
public:
    Pila() = default;

    virtual void apilar(T*);
    virtual T* desapilar();
    bool estaVacia() const;
    virtual void imprimir(ostream&);

    virtual ~Pila() = default;
};

template <typename T>
void Pila<T>::apilar(T* dato) {
    this->lista.insertarPrimero(dato);
}

template <typename T>
T* Pila<T>::desapilar() {
    T* primero;
    if (this->lista.removerPrimero(primero)) {
        return primero;
    }

    return nullptr;
}

template <typename T>
void Pila<T>::imprimir(ostream& os) {
    this->lista.imprimir(os);
}

template <typename T>
bool Pila<T>::estaVacia() const {
    return this->lista.estaVacia();
}

#endif //SESION_DE_CLASE_21_PILA_H