/* 
 * File:   Nodo.h
 * Author: erichuiza
 *
 * Created on November 8, 2024, 12:17 PM
 */

#ifndef NODO_H
#define NODO_H

template<typename T>
class Lista;

template<typename T>
class Nodo {
private:
    Nodo<T>* siguiente;
    T* datos;
public:
    Nodo<T>();
    Nodo<T>(const Nodo<T>&);
    ~Nodo<T>();
    
    void operator=(const Nodo<T>&);
    
    friend class Lista<T>;
};

template<typename T>
Nodo<T>::Nodo() {
    siguiente = {};
    datos = {};
}

template<typename T>
Nodo<T>::Nodo(const Nodo<T>& orig) {
    *this = orig;
}

template<typename T>
void Nodo<T>::operator=(const Nodo<T>& orig) {
    siguiente = orig.siguiente;
    datos = orig.datos;
}

template<typename T>
Nodo<T>::~Nodo<T>() {
    delete datos;
}

#endif /* NODO_H */
