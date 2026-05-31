//
// Created by Eric Huiza on 5/30/26.
//

#ifndef EJERCICIO01_ALUMNO_H
#define EJERCICIO01_ALUMNO_H

#include <iostream>
#include "Persona.h"

using namespace std;

class Alumno : public Persona {
    int codigo;
    int ciclo;
public:
    Alumno();
    Alumno(int dni, int edad, int codigo, int ciclo);

    int getCodigo() const;
    int getCiclo() const;

    ~Alumno() override;
};


#endif //EJERCICIO01_ALUMNO_H
