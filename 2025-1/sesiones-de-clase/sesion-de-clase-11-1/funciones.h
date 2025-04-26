/* 
 * File:   funciones.h
 * Author: erichuiza
 *
 * Created on September 16, 2024, 10:58 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <fstream>
#include "lista.h"
#include <iomanip>

using namespace std;

void cargarDatos(const char*, Lista&, bool(*)(ifstream&, void*&));
void cargarDatos(ifstream&, Lista&, bool(*)(ifstream&, void*&));

void mostrarDatos(const char*, const Lista&, void(*)(ofstream&), void(*)(ofstream&, const void*));
void mostrarDatos(ofstream&, const Lista&, void(*)(ofstream&), void(*)(ofstream&, const void*));

bool cargarMesero(ifstream&, void*&);
void mostrarCabeceraMeseros(ofstream&);
void mostrarMesero(ofstream&, const void*);
void destruirMesero(void*);

void mostrarEntero(const void*);
void destruirEntero(void*);

char* leerCadena(ifstream&, char=',');

#endif /* FUNCIONES_H */

