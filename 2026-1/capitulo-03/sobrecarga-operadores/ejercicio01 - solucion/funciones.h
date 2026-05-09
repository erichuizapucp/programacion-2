//
// Created by Eric Huiza on 3/27/26.
//

#ifndef EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H
#define EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H

#include <iostream>
#include <fstream>
#include "enums.h"

using namespace std;

char* leerCadena(ifstream&, char=',');
Especialidad convertirEspecialidad(const char*);
Estado convertirEstado(const char*);
void imprimirFecha(ostream&, int);
void imprimirHora(ostream&, int);
void imprimirEstado(ostream&, Estado);
void imprimirEspecialidad(ostream&, Especialidad);

#endif //EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H
