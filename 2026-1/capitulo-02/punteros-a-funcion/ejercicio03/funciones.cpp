//
// Created by Eric Huiza on 4/22/26.
//

#include "funciones.h"

void intercambiar(void *a, void *b) {
    void *tmp = *(void**)a;
    *(void **)a = *(void**)b;
    *(void **)b = tmp;
}

int particionar(void *arreglo, int izq, int der,
                int (*comparar)(const void *, const void *)) {
    void **base = (void **)arreglo;
    void *pivote = base[der]; // el pivote es el último elemento
    int i = izq; // posicion para el siguiente elemento menor o igual al pivote

    // Colocar todos los elementos menores o iguales al Pivote a su izquierda
    for (int j = izq; j < der; j++) {
        if (comparar(base[j], pivote) <= 0) {
            intercambiar(base + i, base + j);
            i++;
        }
    }

    // Colocar el pivote en su posición final
    intercambiar(base + i, base + der);
    return i;
}

void ordenar(void *arreglo,
             int cantidadElementos,
             int (*comparar)(const void *, const void *)) {
    if (arreglo == nullptr || comparar == nullptr || cantidadElementos < 2) {
        return;
    }

    int pivote = particionar(arreglo, 0, cantidadElementos - 1, comparar);
    void **base = (void **)arreglo;

    int cantidadIzquierda = pivote;
    int inicioDerecha = pivote + 1;
    int cantidadDerecha = cantidadElementos - inicioDerecha;
    void **subArregloIzquierda = base;
    void **subArregloDerecha = base + inicioDerecha;

    ordenar(subArregloIzquierda, cantidadIzquierda, comparar);
    ordenar(subArregloDerecha, cantidadDerecha, comparar);
}

int compararInt(const void* a, const void* b) {
    int ia = *(int*)a;
    int ib = *(int*)b;

    if (ia < ib) return -1;
    if (ia > ib) return 1;
    return 0;
}

int compararDouble(const void* a, const void* b) {
    double ia = *(double*)a;
    double ib = *(double*)b;

    if (ia < ib) return -1;
    if (ia > ib) return 1;
    return 0;
}

int compararCadenas(const void* a, const void* b) {
    const char* sa = (const char*)a;
    const char* sb = (const char*)b;
    return strcmp(sa, sb);
}