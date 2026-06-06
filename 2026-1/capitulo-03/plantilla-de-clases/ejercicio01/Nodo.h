#ifndef NODO_H
#define NODO_H

template <typename T>
class Lista;

template <typename T>
class Nodo {
    T* dato;
    Nodo<T>* siguiente;
public:
    Nodo();
    Nodo(const Nodo<T>& orig);
    
    T* getDato() const;
    void setDato(T*);
    Nodo<T>* getSiguiente() const;
    void setSiguiente(Nodo<T>*);
    
    friend class Lista<T>;
    
    virtual ~Nodo() = default;
};

template <typename T>
Nodo<T>::Nodo() {
    dato = nullptr;
    siguiente = nullptr;
}

template <typename T>
Nodo<T>::Nodo(const Nodo<T>& orig) {
}

template <typename T>
T* Nodo<T>::getDato() const {
    return dato;
}

template <typename T>
void Nodo<T>::setDato(T* dato) {
    this->dato = dato;
}

template <typename T>
Nodo<T>* Nodo<T>::getSiguiente() const {
    return siguiente;
}

template <typename T>
void Nodo<T>::setSiguiente(Nodo<T>* siguiente) {
    this->siguiente = siguiente;
}

#endif /* NODO_H */

