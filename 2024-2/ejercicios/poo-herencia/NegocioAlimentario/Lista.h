/* 
 * File:   Lista.h
 * Author: erichuiza
 *
 * Created on November 3, 2024, 2:30 PM
 */

#ifndef LISTA_H
#define LISTA_H

template<typename T>
class Lista {
private:
    T* elementos;
    int cantidad;
    
    void incrementarMemoria();
public:
    Lista();
    Lista(const Lista<T>&);
    
    T* getElementos() const;
    int getCantidad() const;
    void setCantidad(const int);
    
    void operator+=(const T&);
    void operator=(const Lista<T>&);
    
    virtual ~Lista();
};

template<typename T>
Lista<T>::Lista() {
    elementos = {};
    cantidad = {};
}

template<typename T>
Lista<T>::Lista(const Lista<T>& orig) {
    *this = orig;
}

template<typename T>
T* Lista<T>::getElementos() const {
    return elementos;
}

template<typename T>
int Lista<T>::getCantidad() const {
    return cantidad;
}

template<typename T>
void Lista<T>::setCantidad(const int cantidad) {
    this->cantidad = cantidad;
}

template<typename T>
void Lista<T>::operator+=(const T& nuevo) {
    incrementarMemoria();
    elementos[cantidad++] = nuevo;
}

template<typename T>
void Lista<T>::incrementarMemoria() {
    if (elementos == nullptr) {
        elementos = new T[cantidad + 1] {};
    }
    else {
        T* aux = new T[cantidad + 1] {};
        for (int i = 0; i < cantidad; i++) {
            aux[i] = elementos[i];
        }
        delete[] elementos;
        elementos = aux;
    }
}

template<typename T>
void Lista<T>::operator=(const Lista<T>& orig) {
    if (elementos != nullptr) {
        delete[] elementos;
    }
    
    elementos = new T[orig.getCantidad()];
    const T* origElementos = orig.getElementos();
    for (int i = 0; i < orig.getCantidad(); i++) {
        elementos[i] = origElementos[i];
    }
}

template<typename T>
Lista<T>::~Lista() {
    delete[] elementos;
}

#endif /* LISTA_H */

