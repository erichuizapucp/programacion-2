//
// Created by Eric Huiza on 3/27/26.
//

#ifndef EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H
#define EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H

#include <iostream>

#include "enums.h"
#include "estructuras.h"

using namespace std;

void cargarPacientes(Clinica&);
void cargarDoctores(Clinica&);
void cargarCitas(Clinica&);

Clinica& operator+=(Clinica&, Paciente&);
Clinica& operator+=(Clinica&, Doctor&);
Clinica& operator+=(Clinica&, Cita&);

bool operator<(Cita&, Cita&);
Cita& operator!(Cita&);

ostream& operator<<(ostream&, Paciente&);
ostream& operator<<(ostream&, Doctor&);
ostream& operator<<(ostream&, Cita&);
ostream& operator<<(ostream&, Clinica&);

void insertarOrdenado(Clinica&, Cita&);
void imprimirFecha(ostream&, int);
void imprimirHora(ostream&, int);
void imprimirEstado(ostream&, Estado);
void imprimirEspecialidad(ostream&, Especialidad);

#endif //EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H
