//
// Created by Eric Huiza on 5/8/26.
//

#ifndef EJERCICIO01_CLINICA_H
#define EJERCICIO01_CLINICA_H

#include "cita/CitaPresencial.h"
#include "cita/CitaVirtual.h"
#include "doctor/DoctorEspecialista.h"
#include "doctor/DoctorGeneral.h"
#include "paciente/PacienteAsegurado.h"
#include "paciente/PacienteParticular.h"

using namespace std;

class Clinica {
    Paciente** pacientes;
    Doctor** doctores;
    Cita** citas;

    int numCitas;
    int numDoctores;
    int numPacientes;

    int capCitas;
    int capDoctores;
    int capPacientes;

    Clinica& operator+=(Paciente*);
    Clinica& operator+=(Doctor*);
    Clinica& operator+=(Cita*);

    void incrementarPacientes();
    void incrementarDoctores();
    void incrementarCitas();

    void insertarOrdenado(Cita*);

    const Paciente* obtenerPacientePorDni(int) const;
    const Doctor* obtenerDoctorPorDni(int) const;

    void asignarPacienteYDoctor(Cita&) const;
    void procesarCita(Cita&) const;
public:
    Clinica();

    void cargarPacientes(const char*);
    void cargarDoctores(const char*);
    void cargarCitas(const char*);
    void procesarCitas() const;
    void cancelarCita(int) const;
    void generarReporte(const char*) const;

    int getNumCitas() const;

    ~Clinica();

    friend ofstream& operator<<(ofstream&, const Clinica&);
};

#endif //EJERCICIO01_CLINICA_H
