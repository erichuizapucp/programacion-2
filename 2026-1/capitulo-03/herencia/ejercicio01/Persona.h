//
// Created by Eric Huiza on 5/13/26.
//

#ifndef EJERCICIO01_PERSONA_H
#define EJERCICIO01_PERSONA_H

#include <fstream>
#include <iostream>

using namespace std;

class Persona {
    int dni;
    char* nombre;
    int edad;
public:
    Persona();
    Persona(const Persona&);

    int getDni() const;
    char* getNombre() const;
    int getEdad() const;

    void leer(ifstream&);
    void imprimir(ofstream&);

    ~Persona();
};


#endif //EJERCICIO01_PERSONA_H
