//
// Created by Eric Huiza on 10/10/25.
//

#ifndef SESION_DE_CLASE_16_REGISTRO_H
#define SESION_DE_CLASE_16_REGISTRO_H

#include <iostream>
#include <iomanip>

using namespace std;

class Registro {
public:
    void leerCuentas(istream&, char**&);
    bool leerCuenta(istream&, char*&);
    char* leerCadena(istream&, char=',');
};


#endif //SESION_DE_CLASE_16_REGISTRO_H