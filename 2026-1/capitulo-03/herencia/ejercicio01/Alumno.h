//
// Created by Eric Huiza on 5/13/26.
//

#ifndef EJERCICIO01_ALUMNO_H
#define EJERCICIO01_ALUMNO_H

#include "Persona.h"
#include <iostream>
#include <fstream>

using namespace std;

class Alumno : public Persona {
    int codigo;
    char* facultad;
public:
    Alumno();
    Alumno(const Alumno&);

    void leer(ifstream&);
    void imprimir(ofstream&);

    ~Alumno();
};


#endif //EJERCICIO01_ALUMNO_H
