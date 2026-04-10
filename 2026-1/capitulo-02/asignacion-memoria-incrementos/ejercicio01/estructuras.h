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
    char* nombre;
    Especialidad especialidad;
};

struct Cita {
    int fecha;
    int hora;
    int dniPaciente;
    int dniDoctor;
    const Paciente* paciente;
    const Doctor* doctor;
    Estado estado;
};

struct Clinica {
    Paciente* pacientes;
    Doctor* doctores;
    Cita* citas;
};

#endif //EJERCICIO_OPERADORES_CLINICA_ESTRUCTURAS_H
