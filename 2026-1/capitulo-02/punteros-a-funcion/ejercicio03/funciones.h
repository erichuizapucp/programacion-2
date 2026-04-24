//
// Created by Eric Huiza on 4/22/26.
//

#ifndef EJERCICIO03_FUNCIONES_H
#define EJERCICIO03_FUNCIONES_H

#include <cstring>

using namespace std;

void intercambiar(void *, void *);
int particionar(void *, int, int, int (*)(const void *, const void *));
void ordenar(void *, int, int (*)(const void *, const void *));

int compararInt(const void* a, const void* b);
int compararDouble(const void* a, const void* b);
int compararCadenas(const void* a, const void* b);

#endif //EJERCICIO03_FUNCIONES_H
