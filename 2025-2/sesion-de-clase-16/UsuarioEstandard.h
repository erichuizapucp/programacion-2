//
// Created by Eric Huiza on 10/10/25.
//

#ifndef SESION_DE_CLASE_16_USUARIOESTANDARD_H
#define SESION_DE_CLASE_16_USUARIOESTANDARD_H

#include "Usuario.h"


class UsuarioEstandard : public Usuario {
    char** contactos;
public:
    UsuarioEstandard();
    UsuarioEstandard(const UsuarioEstandard&);
    UsuarioEstandard(char*, char*, char*, char*);
    UsuarioEstandard(int, int);
    UsuarioEstandard(char*, char*, char*, char*, int, int);

    void setContactos(char**);
    char** getContactos() const;

    istream& leer(istream&);
    ostream& imprimir(ostream&) const;

    UsuarioEstandard& operator=(const UsuarioEstandard&);
    UsuarioEstandard& operator+=(const Publicacion&);

    ~UsuarioEstandard();
};

istream& operator>>(istream&, UsuarioEstandard&);
ostream& operator<<(ostream&, const UsuarioEstandard&);


#endif //SESION_DE_CLASE_16_USUARIOESTANDARD_H