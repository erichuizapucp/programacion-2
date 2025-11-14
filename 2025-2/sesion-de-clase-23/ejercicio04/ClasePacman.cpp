//
// Created by Eric Huiza on 11/14/25.
//

#include "ClasePacman.h"

int ClasePacman::puntaje = 0;

ClasePacman::ClasePacman() {
}

ClasePacman::ClasePacman(const ClasePacman& orig) {
}

// Los atributos estáticos solo deben ser modificados por métodos estáticos
void ClasePacman::incrementarPuntaje() {
    puntaje++;
}

// No se debe realizar, sólo usar métodos estáticos
void ClasePacman::incrementar() {
    this->puntaje++;
}

ClasePacman::~ClasePacman() {
}