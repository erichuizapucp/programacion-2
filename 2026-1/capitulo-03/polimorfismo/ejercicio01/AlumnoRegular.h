//
// Created by Eric Huiza on 5/30/26.
//

#ifndef EJERCICIO01_ALUMNOREGULAR_H
#define EJERCICIO01_ALUMNOREGULAR_H

#include <iostream>

#include "Alumno.h"

using namespace std;

class AlumnoRegular : public Alumno {
    int numCreditos;
public:
    AlumnoRegular();
    AlumnoRegular(int dni, int edad, int codigo, int ciclo, int numCreditos);

    void imprimir() const override;

    ~AlumnoRegular() override;
};
#endif //EJERCICIO01_ALUMNOREGULAR_H
