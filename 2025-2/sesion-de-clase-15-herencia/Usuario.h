//
// Created by Eric Huiza on 10/6/25.
//

#ifndef SESION_DE_CLASE_15_HERENCIA_USUARIO_H
#define SESION_DE_CLASE_15_HERENCIA_USUARIO_H

#include "Registro.h"
#include "Publicacion.h"

using namespace std;

class Usuario : public Registro {
    char* nombre;
    char* correo;
    char* facultad;
    int edad;
    Publicacion* publicacion;
public:
    Usuario& operator+=(const Publicacion&);
};


#endif //SESION_DE_CLASE_15_HERENCIA_USUARIO_H