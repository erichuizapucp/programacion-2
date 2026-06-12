//
// Created by Eric Huiza on 6/12/26.
//

#include "Curso.h"

int Curso::getCodigo() const {
    return codigo;
}

string Curso::getNombre() const {
    return nombre;
}

int Curso::getCiclo() const {
    return ciclo;
}

void Curso::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Curso::setNombre(string nombre) {
    this->nombre = nombre;
}

void Curso::setCiclo(int ciclo) {
    this->ciclo = ciclo;
}