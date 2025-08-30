//
// Created by Eric Huiza on 8/29/25.
//

#ifndef EJERCICIO02_FUNCIONES_H
#define EJERCICIO02_FUNCIONES_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "estructuras.h"

using namespace std;

void cargarUsuarios(const char*, Usuario*&);
void imprimirUsuarios(const char*, const Usuario*);

bool operator>>(istream&, Usuario&);
ostream& operator<<(ostream&, const Usuario&);

char* leerCadena(istream&, char=',');

#endif //EJERCICIO02_FUNCIONES_H