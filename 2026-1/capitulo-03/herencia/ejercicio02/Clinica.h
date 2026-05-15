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
    PacienteParticular* pacientesParticulares;
    PacienteAsegurado* pacientesAsegurados;
    DoctorGeneral* doctoresGenerales;
    DoctorEspecialista* doctoresEspecialistas;
    CitaPresencial* citasPresenciales;
    CitaVirtual* citasVirtuales;

    int numCitasPresenciales;
    int numCitasVirtuales;
    int numDoctoresGenerales;
    int numDoctoresEspecialistas;
    int numPacientesParticulares;
    int numPacientesAsegurados;

    int capCitasPresenciales;
    int capCitasVirtuales;
    int capDoctoresGenerales;
    int capDoctoresEspecialistas;
    int capPacientesParticulares;
    int capPacientesAsegurados;

    Clinica& operator+=(const PacienteParticular&);
    Clinica& operator+=(const PacienteAsegurado&);
    Clinica& operator+=(const DoctorGeneral&);
    Clinica& operator+=(const DoctorEspecialista&);
    Clinica& operator+=(const CitaPresencial&);
    Clinica& operator+=(const CitaVirtual&);

    void incrementarPacientesParticulares();
    void incrementarPacientesAsegurados();
    void incrementarDoctoresGenerales();
    void incrementarDoctoresEspecialistas();
    void incrementarCitasPresenciales();
    void incrementarCitasVirtuales();

    void insertarOrdenado(const CitaPresencial&);
    void insertarOrdenado(const CitaVirtual&);

    const PacienteParticular* obtenerPacienteParticularPorDni(int) const;
    const PacienteAsegurado* obtenerPacienteAseguradoPorDni(int) const;
    const DoctorGeneral* obtenerDoctorGeneralPorDni(int) const;
    const DoctorEspecialista* obtenerDoctorEspecialistaPorDni(int) const;

    void asignarPacienteYDoctor(Cita&) const;
    void procesarCita(CitaPresencial&) const;
    void procesarCita(CitaVirtual&) const;

    friend ofstream& operator<<(ofstream&, const Clinica&);
public:
    Clinica();

    void cargarPacientes(const char*);
    void cargarDoctores(const char*);
    void cargarCitas(const char*);
    void procesarCitas() const;
    void cancelarCitaPresencial(int) const;
    void cancelarCitaVirtual(int) const;
    void generarReporte(const char*) const;

    //TODO: Esto es sólo de forma temporal
    int getNumCitas() const;

    ~Clinica();
};

ofstream& operator<<(ofstream&, const Clinica&);

#endif //EJERCICIO01_CLINICA_H
