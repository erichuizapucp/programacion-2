//
// Created by Eric Huiza on 3/27/26.
//

#ifndef EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H
#define EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "enum.h"

using namespace std;

void cargarDatos(void*&, const char*, const char*, const char*, const char*);
void cargarPacientes(const char*, void*&);
void cargarDoctores(const char*, void*&);
void cargarCitas(const char*, void*);
void cargarCancelaciones(const char*, void*);

bool leerPaciente(ifstream&, void*&);
bool leerDoctor(ifstream&, void*&);
bool leerCita(ifstream&, void*&, int&);
bool leerCancelacion(ifstream&, void*&, int&);

void incrementarCapacidad(void**&, int, int&);
void agregarRegistroExacto(void**&, void*);
char* leerCadena(ifstream&, char = ',');

void* buscarPaciente(int, const void*);
void* buscarDoctor(int, const void*);
void cancelarCitas(void*);
void cancelarCita(void*&);
bool esMismaCita(const void*, int, int, int);
void procesarCancelacionesPaciente(void**);
void aplicarCancelacionPaciente(void**, void*);
void* buscarCitaPaciente(void**, int, int, int);

void imprimirReporte(ofstream&, const void*);
void imprimirCitasPaciente(ofstream&, const void*, const void*);
void imprimirDetalleCita(ofstream&, const void*, const void*);
void imprimirCita(ofstream&, int, int, int);
void imprimirPaciente(ofstream&, const void*);
void imprimirDoctor(ofstream&, const void*);
void imprimirFecha(ostream&, int);
void imprimirHora(ostream&, int);
void imprimirEstado(ostream&, int);
void imprimirEspecialidad(ostream&, int);

void liberarPacientes(void*&);
void liberarPaciente(void*&);
void liberarCitasPaciente(void*&);
void liberarCancelacionesPaciente(void*&);
void liberarDoctores(void*&);
void liberarClinica(void*&);

#endif //EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H
