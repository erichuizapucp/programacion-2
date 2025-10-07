//
// Created by Eric Huiza on 10/3/25.
//

#include "CompararEdad.h"

int CompararEdad::ascendente(const void* a, const void* b) {
    Usuario usuarioA = *(Usuario*)a;
    Usuario usuarioB = *(Usuario*)b;

    return usuarioA.getEdad() - usuarioB.getEdad();
}

int CompararEdad::descendente(const void* a, const void* b) {
    Usuario usuarioA = *(Usuario*)a;
    Usuario usuarioB = *(Usuario*)b;

    return usuarioB.getEdad() - usuarioA.getEdad();
}