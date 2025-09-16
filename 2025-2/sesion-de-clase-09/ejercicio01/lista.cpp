//
// Created by Eric Huiza on 9/11/25.
//

#include "lista.h"

void* crearLista() {
    void** lista = new void*[2];
    lista[CABEZA] = nullptr; // puntero a la cabeza de la lista
    lista[COLA] = nullptr; // puntero a la cola de la lista

    return lista;
}

bool listaVacia(void* lista) {
    void** aux = (void**)lista;
    return aux[CABEZA] == nullptr;
}

void insertarSiguiente(void* lista, void* nodo, void* dato) {
    void** auxLista = (void**)lista;

    void** nuevo = new void*[2];
    nuevo[DATO] = dato;
    nuevo[SIGUIENTE] = nullptr; // por si se inserta al final

    if (nodo == nullptr) { // insertar al inicio
        if (listaVacia(lista)) {
            auxLista[CABEZA] = nuevo;
            auxLista[COLA] = nuevo;
        }
        else {
            nuevo[SIGUIENTE] = auxLista[CABEZA]; // Siguiente igual a la cabeza anterior
            auxLista[CABEZA] = nuevo; // la cabeza ahora es el nuevo nodo
        }
    }
    else {
        void** auxNodo = (void**)nodo;
        nuevo[SIGUIENTE] = auxNodo[SIGUIENTE];
        auxNodo[SIGUIENTE] = nuevo;

        if (nodo == auxLista[COLA]) { // si se inserta al final
            auxLista[COLA] = nuevo;
        }
    }
}

bool removerSiguiente(void* lista, void* nodo, void*& dato) {
    void** auxLista = (void**)lista;

    if (nodo == nullptr) { // eliminar al inicio
        if (listaVacia(lista)) {
            return false;
        }

        void** cabeza = (void**)auxLista[CABEZA];
        dato = cabeza[DATO];

        if (auxLista[CABEZA] == auxLista[COLA]) {
            delete cabeza;
            auxLista[CABEZA] = nullptr;
            auxLista[COLA] = nullptr;
            return true;
        }

        auxLista[CABEZA] = cabeza[SIGUIENTE];
        delete cabeza;
        return true;
    }

    void** auxNodo = (void**)nodo;
    if (auxLista[COLA] == nullptr) {
        return false;
    }

    void** siguiente = (void**)auxNodo[SIGUIENTE];
    dato = siguiente[DATO];
    auxNodo[SIGUIENTE] = siguiente[SIGUIENTE];

    if (siguiente == auxLista[COLA]) { // si se elimina el ultimo nodo
        auxLista[COLA] = nodo;
    }

    delete siguiente;
    return true;
}

void* buscar(void* lista, void* valor) {
    void** auxLista = (void**)lista;
    void** actual = (void**)auxLista[CABEZA];

    while (actual != nullptr) {
        if (actual[DATO] == valor) {
            return actual;
        }
        actual = (void**)actual[SIGUIENTE];
    }

    return nullptr;
}

void* primero(void* lista) {
    void** auxLista = (void**)lista;
    return auxLista[CABEZA];
}

void* ultimo(void* lista) {
    void** auxLista = (void**)lista;
    return auxLista[COLA];
}

void imprimirLista(ostream& os,
                   void* lista,
                   void (*imp)(ostream&, void*)) {
    void** auxLista = (void**)lista;
    void** actual = (void**)auxLista[CABEZA];

    while (actual != nullptr) {
        imp(os, actual[DATO]);
        actual = (void**)actual[SIGUIENTE];
    }
}

void destruir(void* lista) {
    void** auxLista = (void**)lista;
    void** actual = (void**)auxLista[CABEZA];

    while (actual != nullptr) {
        void** siguiente = (void**)actual[SIGUIENTE];
        delete actual;
        actual = siguiente;
    }

    delete[] auxLista;
}

void imprimirEntero(ostream &os, void *dato) {
    os << *(int*) dato << endl;
}

void imprimirDouble(ostream &os, void* dato) {
    os << *(double*) dato << endl;
}

void imprimirCadena(ostream & os, void* dato) {
    os << *(const char**)dato << endl;
}
