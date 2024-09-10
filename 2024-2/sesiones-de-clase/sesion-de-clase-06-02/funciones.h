/* 
 * File:   funciones.h
 * Author: erichuiza
 *
 * Created on September 6, 2024, 12:20 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#include "enums.h"

using namespace std;

const int INCREMENTO = 5;
const int BUFFER_CAP = 1000;

void cargarMesas(const char*, int**&);
void cargarMesas(ifstream&, int**&);
void cargarReservas(const char*, int**&, char**&);
void cargarReservas(ifstream&, int**&, char**&);

void mostrarMesas(const char*, const int**);
void mostrarMesas(ofstream&, const int**);

void mostrarReservas(const char*, const int**, const char**);
void mostrarReservas(ofstream&, const int**, const char**);

void incrementar(int*&, int, int, bool=true);
void incrementar(char**&, int, int, bool=true);

char* leerCadena(ifstream&, char=',');

void asignarValores(int*&, int*&, char**&, int, int, int, char*);

#endif /* FUNCIONES_H */

