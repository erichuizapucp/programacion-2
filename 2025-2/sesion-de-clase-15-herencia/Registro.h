//
// Created by Eric Huiza on 10/6/25.
//

#ifndef SESION_DE_CLASE_15_HERENCIA_REGISTRO_H
#define SESION_DE_CLASE_15_HERENCIA_REGISTRO_H

#include <iostream>

using namespace std;

class Registro {
    char* cuenta;
    int fecha;
public:
    leer();
    imprimir();
};

istream& operator>>(istream& os, Registro&);
ostream& operator<<(ostream& os, const Registro&);

#endif //SESION_DE_CLASE_15_HERENCIA_REGISTRO_H