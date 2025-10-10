//
// Created by Eric Huiza on 9/26/25.
//

#ifndef SESION_DE_CLASE_12_REDSOCIAL_H
#define SESION_DE_CLASE_12_REDSOCIAL_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Usuario.h"
#include "Publicacion.h"
#include "UsuarioEstandard.h"

using namespace std;

class RedSocial {
    UsuarioEstandard* usuarios;
    int cantUsuarios;
    int capacidad;

    void incrementar();
    RedSocial& operator+=(const UsuarioEstandard&);
public:
    RedSocial();

    void cargarUsuarios(const char*);
    void cargarPublicaciones(const char*);
    void generarReporte(const char*) const;

    UsuarioEstandard& operator[](int) const;
    UsuarioEstandard& operator[](const char*) const;
    UsuarioEstandard& at(int) const;

    ~RedSocial();
};

int compararUsuarios(const void*, const void*);


#endif //SESION_DE_CLASE_12_REDSOCIAL_H