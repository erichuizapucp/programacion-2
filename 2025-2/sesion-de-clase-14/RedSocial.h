//
// Created by Eric Huiza on 9/26/25.
//

#ifndef SESION_DE_CLASE_12_REDSOCIAL_H
#define SESION_DE_CLASE_12_REDSOCIAL_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Usuario.h"

using namespace std;

class RedSocial {
    Usuario* usuarios;
    int cantUsuarios;
    int capacidad;

    void incrementar();
    RedSocial& operator+=(const Usuario&);
public:
    RedSocial();

    void cargarUsuarios(const char*);
    void generarReporteUsuarios(const char*) const;

    Usuario& operator[](int) const;
    Usuario& at(int) const;

    ~RedSocial();
};

int compararUsuarios(const void*, const void*);


#endif //SESION_DE_CLASE_12_REDSOCIAL_H