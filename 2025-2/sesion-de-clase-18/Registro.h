//
// Created by Eric Huiza on 10/24/25.
//

#ifndef SESION_DE_CLASE_18_REGISTRO_H
#define SESION_DE_CLASE_18_REGISTRO_H

#include <iostream>
#include <cstring>

using namespace std;
class Registro {
protected:
    char* leerCadena(istream&, char = ',');
    void setCadena(char*&, const char*);
};


#endif //SESION_DE_CLASE_18_REGISTRO_H