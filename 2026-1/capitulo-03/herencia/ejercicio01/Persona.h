//
// Created by Eric Huiza on 5/13/26.
//

#ifndef EJERCICIO01_PERSONA_H
#define EJERCICIO01_PERSONA_H

#include <fstream>
#include <iostream>

#include "Registro.h"

using namespace std;

class Persona : public Registro {
    int dni;
    char* nombre;
    int edad;
public:
    Persona();
    Persona(const Persona&);

    int getDni() const;
    char* getNombre() const;
    int getEdad() const;

    void setDni(int);
    void setNombre(char*);
    void setEdad(int);

    void leer(ifstream&);
    void imprimir(ostream&) const;

    ~Persona();
};

ostream& operator<<(ostream&, const Persona&);

#endif //EJERCICIO01_PERSONA_H
