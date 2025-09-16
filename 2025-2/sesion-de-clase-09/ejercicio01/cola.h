//
// Created by Eric Huiza on 9/15/25.
//

#ifndef EJERCICIO01_COLA_H
#define EJERCICIO01_COLA_H

#include "lista.h"

using namespace std;

void* crearCola();
bool colaVacia(void*);
void encolar(void*, void*);
bool desencolar(void*, void*&);
void imprimirCola(ostream&, void*, void (*)(ostream&, void*));
void destruirCola(void*);

#endif //EJERCICIO01_COLA_H