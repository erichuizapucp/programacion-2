#include "lista.h"

void inicializar(Lista& lista, void(*destruir)(void* datos)) {
    lista.cabeza = nullptr;
    lista.cola = nullptr;
    lista.longitud = 0;
    lista.destruir = destruir;
}

void destruir(Lista& lista) {
    while (lista.longitud > 0) {
        void* datos;
        if (remover(lista, nullptr, datos) && lista.destruir != nullptr) {
            lista.destruir(datos);
        }
    }
}

bool remover(Lista& lista, Nodo* elemento, void*& datos) {
    if (lista.longitud == 0) {
        return false;
    }
    
    Nodo* anterior;
    
    if (elemento == nullptr) {
        datos = lista.cabeza->datos;
        anterior = lista.cabeza;
        lista.cabeza = lista.cabeza->siguiente;
        
        if (lista.longitud == 1) {
            lista.cola = nullptr;
        }
    }
    else {
        if (elemento->siguiente == nullptr) {
            return false;
        }
        datos = elemento->siguiente->datos;
        anterior = elemento->siguiente;
        elemento->siguiente = elemento->siguiente->siguiente;
        
        if (elemento->siguiente == nullptr) {
            lista.cola = elemento;
        }
    }
    delete anterior;
    lista.longitud--;
    
    return true;
}

void insertar(Lista& lista, Nodo* elemento, const void* datos) {
    Nodo* nuevo = new Nodo;
    nuevo->datos = (void*)datos;
    
//  insertar en la cabeza de la cola
    if (elemento == nullptr) {
        if (lista.longitud == 0) {
            lista.cola = nuevo;
        }
        
        nuevo->siguiente = lista.cabeza;
        lista.cabeza = nuevo;
    }
    else {
        if (elemento->siguiente == nullptr) {
            lista.cola = nuevo;
        }
        
        nuevo->siguiente = elemento->siguiente;
        elemento->siguiente = nuevo;
    }
    
    lista.longitud++;
}

void recorrer(const Lista& lista, void(*func)(const void* datos)) {
    const Nodo* actual = lista.cabeza;
    
    while (actual != nullptr) {
        func(actual->datos);
        actual = actual->siguiente;
    }
}

void recorrer(const Lista& lista, ofstream& archivo, void(*func)(ofstream& archivo, const void* datos)) {
    const Nodo* actual = lista.cabeza;
    
    while (actual != nullptr) {
        func(archivo, actual->datos);
        actual = actual->siguiente;
    }
}