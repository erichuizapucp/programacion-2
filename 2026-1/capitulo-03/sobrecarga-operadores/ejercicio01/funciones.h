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

void cargarPacientes(const char*, Paciente*&);
void cargarDoctores(const char*, Doctor*&);
void cargarCitas(const char*, Cita*&);

void incrementarCitas(Cita*&, int, int&);
void incrementarPacientes(Paciente*&, int, int&);
void incrementarDoctores(Doctor*&, int, int&);

bool operator>>(ifstream&, Paciente&);
bool operator>>(ifstream&, Doctor&);
bool operator>>(ifstream&, Cita&);

char* leerCadena(ifstream&, char=',');
Especialidad convertirEspecialidad(const char*);
Estado convertirEstado(const char*);

bool operator<(const Cita&, const Cita&);
Cita& operator!(Cita&);

ostream& operator<<(ostream&, const Paciente&);
ostream& operator<<(ostream&, const Doctor&);
ostream& operator<<(ostream&, const Cita&);
ostream& operator<<(ostream&, const Clinica&);

const Paciente* obtenerPacientePorDni(int, const Paciente*);
const Doctor* obtenerDoctorPorDni(int, const Doctor*);
void procesarCitas(Clinica&);

void insertarOrdenado(Cita*, int&, const Cita&);
void imprimirFecha(ostream&, int);
void imprimirHora(ostream&, int);
void imprimirEstado(ostream&, Estado);
void imprimirEspecialidad(ostream&, Especialidad);

#endif //EJERCICIO_OPERADORES_CLINICA_FUNCIONES_H
