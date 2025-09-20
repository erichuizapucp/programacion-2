//
// Created by Eric Huiza on 9/15/25.
//

#include "../includes/cola.h"

void* crearCola() {
    return crearLista();
}

bool colaVacia(void* cola) {
    return listaVacia(cola);
}

void encolar(void* cola, void* dato) {
    insertarSiguiente(cola, ultimo(cola), dato);
}

bool desencolar(void* cola, void*& dato) {
    return removerSiguiente(cola, nullptr, dato);
}

void imprimirCola(ostream& os,
                  void* cola,
                  void (*imp)(ostream& archivo, void* dato)) {
    imprimirLista(os, cola, imp);
}

void destruirCola(void* cola) {
    destruir(cola);
}