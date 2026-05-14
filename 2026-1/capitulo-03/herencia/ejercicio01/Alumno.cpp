//
// Created by Eric Huiza on 5/13/26.
//

#include "Alumno.h"

Alumno::Alumno() : Persona() {
    codigo = 0;
    facultad = nullptr;
}

// Alumno(const Alumno&);
//
// void leer(ifstream&);
// void imprimir(ofstream&);

Alumno::~Alumno() {
    delete[] facultad;
}