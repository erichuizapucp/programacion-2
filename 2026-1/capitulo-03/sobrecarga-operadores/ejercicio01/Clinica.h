//
// Created by Eric Huiza on 5/8/26.
//

#ifndef EJERCICIO01_CLINICA_H
#define EJERCICIO01_CLINICA_H
#include "Cita.h"
#include "Doctor.h"
#include "Paciente.h"


class Clinica {
    Paciente* pacientes;
    Doctor* doctores;
    Cita* citas;

    int numCitas;
    int numDoctors;
    int numPacientes;
    int capCitas;
    int capDoctor;
    int capPaciente;
public:
    Clinica();

    void cargarPacientes(const char*);
    void cargarDtores(const char*);
    void cargarCitas(const char*);
    void procesarCitas();
    void cancelarCita(int);
    void generarReporte(const char*) const;

    ~Clinica();
};


#endif //EJERCICIO01_CLINICA_H
