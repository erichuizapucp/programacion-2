//
// Created by Eric Huiza on 10/6/25.
//

#ifndef SESION_DE_CLASE_15_HERENCIA_USUARIOVERIFICADO_H
#define SESION_DE_CLASE_15_HERENCIA_USUARIOVERIFICADO_H

#include "UsuarioEstandard.h"

using namespace std;

class UsuarioVerificado : public UsuarioEstandard {
    Usuario* seguidores;
};


#endif //SESION_DE_CLASE_15_HERENCIA_USUARIOVERIFICADO_H