//
// Created by Eric Huiza on 5/8/26.
//

#ifndef EJERCICIO01_CLINICA_H
#define EJERCICIO01_CLINICA_H

#include "Cita.h"
#include "Doctor.h"
#include "Paciente.h"

using namespace std;

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

    Clinica& operator+=(const Paciente&);
    Clinica& operator+=(const Doctor&);
    Clinica& operator+=(const Cita&);

    void incrementarPacientes();
    void incrementarDoctores();
    void incrementarCitas();

    void insertarOrdenado(const Cita&);

    const Paciente* obtenerPacientePorDni(int) const;
    const Doctor* obtenerDoctorPorDni(int) const;
public:
    Clinica();

    void cargarPacientes(const char*);
    void cargarDoctores(const char*);
    void cargarCitas(const char*);
    void procesarCitas();
    void cancelarCita(int);
    void generarReporte(const char*) const;

    //TODO: Esto es sólo de forma temporal
    int getNumCitas() const;
    Cita* getCita(int) const;

    ~Clinica();
};

ofstream& operator<<(ofstream&, const Clinica&);

#endif //EJERCICIO01_CLINICA_H
