#include <iostream>

#include <cstdlib>

#include "ClasePacman.h"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    // Esto es lo correcto
    ClasePacman::incrementarPuntaje();

    // No debe modificar atributos estáticos.
    ClasePacman p;
    p.incrementar();

    return 0;
}