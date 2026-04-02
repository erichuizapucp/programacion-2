//
// Created by Eric Huiza on 3/27/26.
//

#ifndef EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H
#define EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H

#include <iostream>
#include <fstream>

#include "enums.h"
#include "estructuras.h"

using namespace std;

void cargarPacientes(const char*, Paciente*&, int&);
void cargarPacientes(const char*, Paciente*&);

bool operator>>(ifstream&, Paciente&);

char* leerCadena(ifstream&, char=',');

void cargarDoctores(Clinica&);
void cargarCitas(Clinica&);

Clinica& operator+=(Clinica&, Paciente&);
Clinica& operator+=(Clinica&, Doctor&);
Clinica& operator+=(Clinica&, Cita&);

bool operator<(Cita&, Cita&);
Cita& operator!(Cita&);

ostream& operator<<(ostream&, const Paciente&);
ostream& operator<<(ostream&, const Doctor&);
ostream& operator<<(ostream&, const Cita&);
ostream& operator<<(ostream&, const Clinica&);

void insertarOrdenado(Clinica&, Cita&);
void imprimirFecha(ostream&, int);
void imprimirHora(ostream&, int);
void imprimirEstado(ostream&, Estado);
void imprimirEspecialidad(ostream&, Especialidad);

#endif //EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H
