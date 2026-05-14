//
// Created by Eric Huiza on 5/13/26.
//

#ifndef EJERCICIO_CADENAS_MANEJADORCADENAS_H
#define EJERCICIO_CADENAS_MANEJADORCADENAS_H

#include "Cadena.h"
#include <fstream>
#include <iostream>

using namespace std;
class ManejadorCadenas {
    Cadena* cadenas;
    int numCadenas;
public:
    ManejadorCadenas();

    void cargarCadenas(const char*);
    void imprimirCadenas() const;

    ~ManejadorCadenas();
};

int cmpCadena(const void*, const void*);


#endif //EJERCICIO_CADENAS_MANEJADORCADENAS_H
