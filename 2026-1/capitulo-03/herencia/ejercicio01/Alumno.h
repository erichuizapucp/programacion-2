//
// Created by Eric Huiza on 5/13/26.
//

#ifndef EJERCICIO01_ALUMNO_H
#define EJERCICIO01_ALUMNO_H

#include "Persona.h"
#include <iostream>
#include <fstream>

using namespace std;

class Alumno : public Persona {
    int codigo;
    char* facultad;
public:
    Alumno();
    Alumno(const Alumno&);

    int getCodigo() const;
    char* getFacultad() const;

    void setCodigo(int);
    void setFacultad(char*);

    void leer(ifstream&);
    void imprimir(ostream&) const;

    ~Alumno();
};

ostream& operator<<(ostream&, const Alumno&);

#endif //EJERCICIO01_ALUMNO_H
