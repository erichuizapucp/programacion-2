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

using namespace std;

const int INCREMENTO = 5;
void cargarMesas(const char*, int**&);
void cargarMesas(ifstream&, int**&);
void cargarReservas(const char*, int**&, char**&);
void cargarReservas(ifstream&, int**&, char**&);

void incrementar(int*&, int*&, int, int);
void incrementar(char**&, int, int);

char* leerCadena(ifstream&, char=',');

#endif /* FUNCIONES_H */

