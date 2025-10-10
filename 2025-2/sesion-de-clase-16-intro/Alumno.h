//
// Created by Eric Huiza on 10/10/25.
//

#ifndef SESION_DE_CLASE_16_INTRO_ALUMNO_H
#define SESION_DE_CLASE_16_INTRO_ALUMNO_H

#include <iostream>

#include "Registro.h"

using namespace std;

class Alumno : public Registro {
    char* nombre;
    char* dni;
    int codigo;
public:
    Alumno();
    Alumno(char*, char*, int);
    Alumno(const Alumno&);

    char* getNombre() const;
    void setNombre(char*);
    char* getDni() const;
    void setDni(char*);
    int getCodigo() const;
    void setCodigo(int);

    Alumno& operator=(const Alumno&);

    void imprimir();

    ~Alumno();
};


#endif //SESION_DE_CLASE_16_INTRO_ALUMNO_H