//
// Created by Eric Huiza on 5/8/26.
//

#ifndef EJERCICIO01_CLINICA_H
#define EJERCICIO01_CLINICA_H

#include "Cita.h"
#include "Doctor.h"
#include "Paciente.h"

#include <fstream>

using namespace std;

class Clinica {
    Paciente* pacientes;
    Doctor* doctores;
    Cita* citas;

    int numeroCitas;
    int numeroDoctores;
    int numeroPacientes;

    int capCitas;
    int capDoctores;
    int capPacientes;

    void incrementarPacientes();
    void incrementarCitas();
    void incrementarDoctores();

    Clinica& operator+=(const Paciente&);
    Clinica& operator+=(const Doctor&);
    Clinica& operator+=(const Cita&);

    Paciente* obtenerPacientePorDni(int dni) const;
    Doctor* obtenerDoctorPorDni(int dni) const;

    void insertarOrdenado(const Cita&);
public:
    Clinica();

    void cargarPacientes(const char*);
    void cargarDoctores(const char*);
    void cargarCitas(const char*);
    void procesarCitas() const;
    void cancelarCita(int) const;
    void generarReporte(const char*) const;

    // TODO: Es público temporalmente mientras no vemos funciones Friend.
    int getNumeroCitas() const;
    Cita* getCita(int index) const;

    ~Clinica();
};

ofstream& operator<<(ofstream&, const Clinica&);

#endif //EJERCICIO01_CLINICA_H
