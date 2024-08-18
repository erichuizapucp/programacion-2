#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Nodo.h"
#include "Persona.h"

using namespace std;

class Nodo;

class Arbol {
private:
    Nodo *arbol;
    void insertarR(Nodo*&, const Persona&);
    void mostrarEnOrdenR(Nodo*);
    void elimina(Nodo*);
    Persona buscarR(Nodo*, int);
public:
    Arbol();
    virtual ~Arbol();
    void crear(const char*);
    void insertar(const Persona&);
    void mostrarEnOrden();
    Persona buscar(int);
};

#endif /* ARBOL_H */
