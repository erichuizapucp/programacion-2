//
// Created by Eric Huiza on 3/27/26.
//

#ifndef EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H
#define EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void cargarPacientes(const char*, int**&, char**&);
void cargarDoctores(const char*, int**&, char**&);
void cargarCitas(const char*, int***&);
void cargarCancelaciones(const char*, int***&);

void incrementarCitas(int***&, int, int&);
void incrementarCancelaciones(int***&, int, int&);
void incrementarPacientes(int**&, char**&, int, int&);
void incrementarDoctores(int**&, char**&, int, int&);

bool leerPaciente(ifstream&, int*&, char*&);
bool leerDoctor(ifstream&, int*&, char*&);
bool leerCita(ifstream&, int**&);
bool leerCancelacion(ifstream&, int**&);

char* leerCadena(ifstream&, char=',');

bool citaMenor(int**, int**);
bool esMismaCita(int**, int, int, int, int);
int** obtenerCitaPorCriterio(int***, int*);
void cancelarCita(int**&);
void cancelarCitas(int***, int***);

ostream& operator<<(ostream&, int**);
ostream& operator<<(ostream&, int***);

int obtenerIndicePacientePorDni(int, int**);
int obtenerIndiceDoctorPorDni(int, int**);
void imprimirReporte(ofstream&, int***, int**, char**, int**, char**);
void imprimirCita(ofstream&, int, int, int);
void imprimirPaciente(ofstream&, int*, const char*);
void imprimirDoctor(ofstream&, int*, const char*);

void insertarOrdenado(int***, int&, int**);
void imprimirFecha(ostream&, int);
void imprimirHora(ostream&, int);
void imprimirEstado(ostream&, int);
void imprimirEspecialidad(ostream&, int);

void liberarPacientes(int**&, char**&);
void liberarDoctores(int**&, char**&);
void liberarCitas(int***&);
void liberarCancelaciones(int***&);

#endif //EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H
