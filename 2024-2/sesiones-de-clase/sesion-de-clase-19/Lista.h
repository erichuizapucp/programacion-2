/* 
 * File:   Lista.h
 * Author: erichuiza
 *
 * Created on November 8, 2024, 12:14 PM
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

template<typename T>
class Lista {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;
    int longitud;
public:
    Lista<T>();
    Lista<T>(const Lista<T>&);
    virtual ~Lista<T>();
    
    Nodo<T>* getCabeza() const;
    Nodo<T>* getCola() const;
    
    void operator=(const Lista<T>&);
    void insertar(Nodo<T>*, T);
    bool remover(Nodo<T>*, T&);
};

template<typename T>
Lista<T>::Lista() {
    cabeza = {};
    cola = {};
    longitud = 0;
}

template<typename T>
Lista<T>::Lista(const Lista<T>& orig) {
    *this = orig;
}

template<typename T>
Nodo<T>* Lista<T>::getCabeza() const {
    return cabeza;
}

template<typename T>
Nodo<T>* Lista<T>::getCola() const {
    return cola;
}

template<typename T>
void Lista<T>::operator=(const Lista<T>& orig) {
    cabeza = orig.cabeza;
    cola = orig.cola;
    longitud = orig.longitud;
}

template<typename T>
void Lista<T>::insertar(Nodo<T>* elemento, T datos) {
    Nodo<T>* nuevo = new Nodo<T>;
    nuevo->datos = new T(datos);
    
//  insertar en la cabeza de la cola
    if (elemento == nullptr) {
        if (longitud == 0) {
            cola = nuevo;
        }
        
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }
    else {
        if (elemento->siguiente == nullptr) {
            cola = nuevo;
        }
        
        nuevo->siguiente = elemento->siguiente;
        elemento->siguiente = nuevo;
    }
    
    longitud++;
}

template<typename T>
bool Lista<T>::remover(Nodo<T>* elemento, T& datos) {
    if (longitud == 0) {
        return false;
    }
    
    Nodo<T>* anterior;
    
    if (elemento == nullptr) {
        datos = *cabeza->datos;
        anterior = cabeza;
        cabeza = cabeza->siguiente;
        
        if (longitud == 1) {
            cola = nullptr;
        }
    }
    else {
        if (elemento->siguiente == nullptr) {
            return false;
        }
        datos = *elemento->siguiente->datos;
        anterior = elemento->siguiente;
        elemento->siguiente = elemento->siguiente->siguiente;
        
        if (elemento->siguiente == nullptr) {
            cola = elemento;
        }
    }
    delete anterior;
    longitud--;
    
    return true;
}

template<typename T>
Lista<T>::~Lista() {
    delete cabeza;
    delete cola;
}

#endif /* LISTA_H */

