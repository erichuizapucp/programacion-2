//
// Created by Eric Huiza on 9/15/25.
//

#ifndef EJERCICIO01_COLA_H
#define EJERCICIO01_COLA_H

#include "lista.h"

using namespace std;

void* crearCola();
bool colaVacia(void* cola);
void encolar(void* cola, void* dato);
bool desencolar(void* cola, void*& dato);
void imprimirCola(ostream& os, void* cola, void (*)(ostream&, void*));
void destruirCola(void* cola);

#endif //EJERCICIO01_COLA_H