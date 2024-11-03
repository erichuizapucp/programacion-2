/* 
 * File:   Nodo.h
 * Author: erichuiza
 *
 * Created on May 27, 2024, 12:06 PM
 */

#ifndef NODO_H
#define NODO_H

template <typename T>
class Cola;

template <typename T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente;
public:
    Nodo(T dato);

    friend class Cola<T>;
    
    ~Nodo();
};

template <typename T>
Nodo<T>::Nodo(T dato) : dato(dato), siguiente(nullptr) {
}

template <typename T>
Nodo<T>::~Nodo() {
}

#endif /* NODO_H */

