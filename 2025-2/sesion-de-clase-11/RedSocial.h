//
// Created by Eric Huiza on 9/26/25.
//

#ifndef SESION_DE_CLASE_11_REDSOCIAL_H
#define SESION_DE_CLASE_11_REDSOCIAL_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#include "Usuario.h"

using namespace std;

class RedSocial {
    Usuario* usuarios = nullptr;
    int cantidad = 0;
public:
    void cargarUsuarios(const char* nombreArchivo);
    void generarReporteUsuarios(const char* nombreArchivo) const;
};

#endif //SESION_DE_CLASE_11_REDSOCIAL_H