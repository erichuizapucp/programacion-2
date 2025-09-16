//
// Created by Eric Huiza on 9/15/25.
//

#ifndef EJERCICIO01_PILA_H
#define EJERCICIO01_PILA_H

#include "lista.h"

void* crearPila();
bool pilaVacia(void* pila);
void apilar(void* pila, void* dato);
bool desapilar(void* pila, void*& dato);
void imprimirPila(ostream& os, void* pila, void (*)(ostream&, void*));
void destruirPila(void* pila);

#endif //EJERCICIO01_PILA_H