//
// Created by Eric Huiza on 5/2/26.
//

#ifndef EJERCICIO01_ALUMNO_H
#define EJERCICIO01_ALUMNO_H

#include <iostream>

using namespace std;

class Alumno {
    int dni;
    int codigo;
    char* nombre;
    char* facultad;
    int ciclo;
public:
    Alumno();
    void imprimir();
};


#endif //EJERCICIO01_ALUMNO_H
