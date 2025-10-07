//
// Created by Eric Huiza on 10/6/25.
//

#ifndef SESION_DE_CLASE_15_HERENCIA_PUBLICACION_H
#define SESION_DE_CLASE_15_HERENCIA_PUBLICACION_H

#include "Registro.h"

using namespace std;

class Publicacion : public Registro {
    int id;
    char** menciones;
    char* texto;
public:
    Publicacion& operator+=(const char*);
};


#endif //SESION_DE_CLASE_15_HERENCIA_PUBLICACION_H