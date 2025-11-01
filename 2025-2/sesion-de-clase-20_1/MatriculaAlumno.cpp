//
// Created by Eric Huiza on 10/31/25.
//

#include "MatriculaAlumno.h"

MatriculaAlumno::MatriculaAlumno(Persona& persona){
    this->alumno = persona;
}

ostream& MatriculaAlumno::imprimir(ostream& os) {
    os << "Nombre del Matriculado: " << this->alumno.nombre << endl;
    return os;
}

ostream& operator<<(ostream& os, MatriculaAlumno& matriculaAlumno) {
    return matriculaAlumno.imprimir(os);
}