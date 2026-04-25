//
// Created by Eric Huiza on 9/15/25.
//

#ifndef EJERCICIO01_PILA_H
#define EJERCICIO01_PILA_H

#include "lista.h"

void* crearPila();
bool pilaVacia(void*);
void apilar(void*, void*);
bool desapilar(void*, void*&);
void imprimirPila(ostream&, void*, void (*)(ostream&, void*));
void destruirPila(void*);

#endif //EJERCICIO01_PILA_H