#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <iomanip>
#include "Persona.h"
#include "Arbol.h"

using namespace std;

class Nodo {
private:
    Persona dato;
    Nodo* izq;
    Nodo* der;
public:
    Nodo();
    friend class Arbol;
};

#endif