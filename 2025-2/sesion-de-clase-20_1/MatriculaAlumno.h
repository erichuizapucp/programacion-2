//
// Created by Eric Huiza on 10/31/25.
//

#ifndef SESION_DE_CLASE_20_1_MATRICULAALUMNO_H
#define SESION_DE_CLASE_20_1_MATRICULAALUMNO_H

#include "Persona.h"


class MatriculaAlumno {
    Persona alumno;
    ostream& imprimir(ostream&);
public:
    MatriculaAlumno() = default;
    MatriculaAlumno(Persona&);
    friend ostream& operator<<(ostream&, MatriculaAlumno&);
};


#endif //SESION_DE_CLASE_20_1_MATRICULAALUMNO_H