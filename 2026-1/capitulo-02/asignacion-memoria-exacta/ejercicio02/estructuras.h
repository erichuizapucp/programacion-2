//
// Created by Eric Huiza on 3/27/26.
//

#ifndef EJERCICIO_OPERADORES_CLINICA_ESTRUCTURAS_H
#define EJERCICIO_OPERADORES_CLINICA_ESTRUCTURAS_H

#include "enums.h"

struct Paciente {
    int dni;
    char* nombre;
    int edad;
    char genero;
};

struct Doctor {
    int dni;
    Especialidad especialidad;
};

struct Cita {
    int fecha;
    int hora;
    Paciente paciente;
    Doctor doctor;
    Estado estado;
};

struct Clinica {
    Paciente* pacientes;
    Doctor* doctores;
    Cita* citas;

    int numPacientes;
    int numDoctores;
    int numCitas;
};

#endif //EJERCICIO_OPERADORES_CLINICA_ESTRUCTURAS_H
