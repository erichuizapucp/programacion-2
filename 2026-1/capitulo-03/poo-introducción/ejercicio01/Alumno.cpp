//
// Created by Eric Huiza on 5/2/26.
//

#include "Alumno.h"

void Alumno::imprimir() {
    cout << "Se imprime un alumno" << endl;
}

Alumno::Alumno() {
    dni = 0;
    codigo = -1;
    nombre = nullptr;
    facultad = nullptr;
    ciclo = 0;
}
