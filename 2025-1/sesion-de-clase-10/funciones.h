/* 
 * File:   funciones.h
 * Author: erichuiza
 *
 * Created on September 13, 2024, 1:34 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "iostream"
#include "fstream"
#include "iomanip"

using namespace std;

constexpr int MAX_NUM_MESEROS = 100;

void cargarDatos(const char*, void*&);
void cargarDatos(ifstream&, void*&);
void mostrarDatos(const void*);

bool operator>>(ifstream&, void*&);
ostream& operator<<(ostream&, const void**);

void incrementar(void**&, int&, int&);

char* leerCadena(ifstream&, char=',');
bool cargarMesero(ifstream&, void*&);

int compararNombres(const void*, const void*);
int compararDni(const void*, const void*);
int compararSueldo(const void*, const void*);

bool buscarPorDni(int, const void*, void*&);

int numMeseros(const void*);

#endif /* FUNCIONES_H */
