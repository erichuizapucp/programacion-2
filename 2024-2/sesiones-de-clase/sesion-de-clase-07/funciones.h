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
const int BUFFER_CAP = 100;
const int NUM_DIAS = 7;

void cargarMesasExactas(const char*, int**&);
void cargarMesasExactas(ifstream&, int**&);
void cargarReservasIncremento(const char*, int**&, char**&);
void cargarReservasIncremento(ifstream&, int**&, char**&);
void cargarPropinasExactas(const char*, double***&);
void cargarPropinasExactas(ifstream&, double***&);

void mostrarMesas(const char*, const int**);
void mostrarMesas(ofstream&, const int**);

void mostrarReservas(const char*, const int**, const char**);
void mostrarReservas(ofstream&, const int**, const char**);

void mostrarPropinas(const char*, const double***);
void mostrarPropinas(ofstream&, const double***);

ofstream& operator<<(ofstream&, const double**);
ofstream& operator<<(ofstream&, const double*);

void incrementar(int*&, int, int, bool=true);
void incrementar(char**&, int, int, bool=true);

char* leerCadena(ifstream&, char=',');

void asignarValores(int*&, int*&, char**&, int, int, int, char*);
void asignarPropinasMesero(const double[][BUFFER_CAP], const int, const int*, double**&);
void asignarPropinasDiarias(const double[BUFFER_CAP], const int, double*&);

#endif /* FUNCIONES_H */

