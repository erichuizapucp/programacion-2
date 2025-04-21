/* 
 * File:   funciones.h
 * Author: erichuiza
 *
 * Created on September 6, 2024, 12:20 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <fstream>
#include "estructuras.h"

using namespace std;

constexpr int INCREMENTO = 5;
constexpr int BUFFER_CAP = 100;
constexpr int MAX_MESEROS = 100;
constexpr int NUM_DIAS = 7;
constexpr int NUM_MESAS = 18;

void cargarMesasExactas(const char*, int**&);
void cargarMesasExactas(ifstream&, int**&);
void cargarReservasIncremento(const char*, int**&, char**&);
void cargarReservasIncremento(ifstream&, int**&, char**&);

void cargarMeseros(const char*, Mesero*&, const double***);
void cargarMeseros(ifstream&, Mesero*&, const double***);

void cargarPropinasExactas(const char*, double***&);
void cargarPropinasExactas(ifstream&, double***&);

void cargarPropinasIncremento(const char*, double***&);
void cargarPropinasIncremento(ifstream&, double***&);

void mostrarMesas(const char*, const int**);
void mostrarMesas(ofstream&, const int**);

void mostrarReservas(const char*, const int**, const char**);
void mostrarReservas(ofstream&, const int**, const char**);

void mostrarPropinas(const char*, const double***);
void mostrarPropinas(ofstream&, const double***);

void mostrarMeseros(const char*, const Mesero*);
void mostrarMeseros(ofstream&, const Mesero*);

ofstream& operator<<(ofstream&, const double**);
ofstream& operator<<(ofstream&, const double*);
ofstream& operator<<(ofstream&, const Mesero&);
bool operator>>(ifstream&, Mesero&);
void operator*=(Mesero&, const double**);

void incrementar(int*&, int, int, bool=true);
void incrementar(char**&, int, int, bool=true);
void incrementar(double*&, int&, int&);
void incrementar(double**&, int&, int&);
void incrementar(double***&, int&, int&);

void incrementarPropinasPorDia(double*&, const int, const int, double, int*, int*);
void incrementarPropinasPorMesero(double**&, const double*, const int, const int, int*, int*);

char* leerCadena(ifstream&, char=',');

void asignarValores(int*&, int*&, char**&, int, int, int, char*);
void asignarPropinasMesero(const double*, const int, const int, const int*, double**&);
void asignarPropinasDiarias(const double*, const int, double*&);

void insertarOrdenado(Mesero*&, const Mesero&, const int);
double sumarPropinas(const double*);

#endif /* FUNCIONES_H */

