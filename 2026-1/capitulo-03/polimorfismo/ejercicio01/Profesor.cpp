//
// Created by Eric Huiza on 5/30/26.
//

#include "Profesor.h"


Profesor::Profesor() {
    cantCursos = 0;
}

Profesor::Profesor(int dni, int edad, int cantCursos) : Persona(dni, edad) {
    this->cantCursos = cantCursos;
}

void Profesor::imprimir() const {
    cout << "DNI: " << getDni() << endl;
    cout << "Edad: " << getEdad() << endl;
    cout << "Cant. Cursos: " << cantCursos << endl;
}

Profesor::~Profesor() {
    cout << "Destructor del profesor" << endl;
}
