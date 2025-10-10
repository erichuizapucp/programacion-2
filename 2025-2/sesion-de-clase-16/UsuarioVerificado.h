//
// Created by Eric Huiza on 10/10/25.
//

#ifndef SESION_DE_CLASE_16_USUARIOVERIFICADO_H
#define SESION_DE_CLASE_16_USUARIOVERIFICADO_H

#include "UsuarioEstandard.h"


class UsuarioVerificado : public UsuarioEstandard {
Usuario* seguidores;
public:
    UsuarioVerificado();
    ~UsuarioVerificado();
};


#endif //SESION_DE_CLASE_16_USUARIOVERIFICADO_H