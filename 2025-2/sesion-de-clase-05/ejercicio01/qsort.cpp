//
// Created by Eric Huiza on 9/1/25.
//
#include "qsort.h"

void qsort(Usuario* usuarios, int izq, int der) {
    int limite, pMedio;
    if (izq >= der) return;
    pMedio = (izq + der) / 2;
    cambiar(usuarios[izq],usuarios[pMedio]);
    limite = izq;
    for (int i = izq + 1; i <= der ; ++i) {
        if (strcmp(usuarios[i].nombre, usuarios[izq].nombre) < 0) {
            cambiar(usuarios[i],usuarios[++limite]);
        }
    }
    cambiar(usuarios[izq],usuarios[limite]);
    qsort(usuarios, izq,limite - 1);
    qsort(usuarios,limite + 1, der);
}

void cambiar(Usuario &p1, Usuario &p2){
    Usuario aux = p1;
    p1 = p2;
    p2 = aux;
}