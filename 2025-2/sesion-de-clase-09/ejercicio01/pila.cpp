//
// Created by Eric Huiza on 9/15/25.
//
#include "pila.h"

void* crearPila() {
    return crearLista();
}

bool pilaVacia(void* pila) {
    return listaVacia(pila);
}

void apilar(void* pila, void* dato) {
    insertarSiguiente(pila, nullptr, dato);
}

bool desapilar(void* pila, void*& dato) {
    removerSiguiente(pila, nullptr, dato);
}

void imprimirPila(ostream& os, void* pila, void (*imp)(ostream&, void*)) {
    imprimirLista(os, pila, imp);
}

void destruirPila(void* pila) {
    destruir(pila);
}