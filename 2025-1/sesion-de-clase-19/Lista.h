/* 
 * File:   Lista.h
 * Author: erichuiza
 *
 * Created on June 2, 2025, 2:25 PM
 */

#ifndef LISTA_H
#define LISTA_H

template<typename T>
class Nodo;

template<typename T>
class Cola;

template<typename T>
class ColaPrioritaria;

#include <iostream>
#include "Pedido.h"
#include "Nodo.h"

using namespace std;

template<typename T>
class Lista {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    int longitud;
public:
    Lista();
    
    void insertarPrimero(T*);
    void insertarUltimo(T*);
    void insertar(Nodo<T>*, T*);
    bool removerPrimero(T*&);
    bool removerUltimo(T*&);
    bool remover(Nodo<T>*, T*&);
    bool estaVacia() const;
    
    void imprimir(ostream&);
    
    friend class Cola<T>;
    friend class ColaPrioritaria<T>;
    
    virtual ~Lista();
};

template<typename T>
Lista<T>::Lista() {
    this->cabeza = nullptr;
    this->cola = nullptr;
    this->longitud = 0;
}

template<typename T>
void Lista<T>::insertarPrimero(T* dato) {
    this->insertar(nullptr, dato);
}

template<typename T>
void Lista<T>::insertarUltimo(T* dato) {
    this->insertar(this->cola, dato);
}

template<typename T>
void Lista<T>::insertar(Nodo<T>* nodo, T* dato) {
    Nodo<T>* nuevo = new Nodo<T>;
    nuevo->dato = dato;
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

template<typename T>
bool Lista<T>::removerPrimero(T*& dato) {
    return this->remover(nullptr, dato);
}

template<typename T>
bool Lista<T>::removerUltimo(T*& dato) {
    return this->remover(this->cola, dato);
}

template<typename T>
bool Lista<T>::remover(Nodo<T>* nodo, T*& dato) {
    if (this->estaVacia()) {
        return false;
    }
    
    Nodo<T>* anterior;
    
    if (nodo == nullptr) {
        dato = this->cabeza->dato;
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
        dato = nodo->siguiente->dato;
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

template<typename T>
bool Lista<T>::estaVacia() const {
    return this->longitud == 0;
}

template<typename T>
void Lista<T>::imprimir(ostream& os) {
    const Nodo<T>* nodo = this->cabeza;
    
    while (nodo != nullptr) {
        os << *nodo->dato;
        nodo = nodo->siguiente;
    }
}

template<typename T>
Lista<T>::~Lista() {
    while (this->longitud > 0) {
        T* dato;
        if (remover(nullptr, dato)) {
            delete dato;
        }
    }
}

#endif /* LISTA_H */
