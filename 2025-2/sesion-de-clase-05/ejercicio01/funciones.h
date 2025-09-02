//
// Created by Eric Huiza on 9/1/25.
//

#ifndef EJERCICIO01_FUNCIONES_H
#define EJERCICIO01_FUNCIONES_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "estructuras.h"

using namespace std;

void cargarUsuarios(const char*, Usuario*&);
void cargarPublicaciones(const char*, Publicacion*&);
void imprimirUsuarios(const char*, const Usuario*, const Publicacion*);

void incrementarCapacidadUsuarios(Usuario*&, int&, int&);
void incrementarCapacidadPublicaciones(Publicacion*&, int&, int&);

bool operator>>(ifstream&, Usuario&);
bool operator>>(ifstream&, Publicacion&);

ostream& operator<<(ostream&, const Usuario&);
ostream& operator<<(ostream&, const Publicacion&);

char* leerCadena(istream&, char = ',');

#endif //EJERCICIO01_FUNCIONES_H