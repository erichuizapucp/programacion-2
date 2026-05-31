//
// Created by Eric Huiza on 5/8/26.
//

#ifndef EJERCICIO01_CITA_H
#define EJERCICIO01_CITA_H

#include <iomanip>

#include "../Registro.h"
#include "../enums.h"
#include "../doctor/DoctorEspecialista.h"
#include "../doctor/DoctorGeneral.h"
#include "../paciente/PacienteAsegurado.h"
#include "../paciente/PacienteParticular.h"
#include "../funciones.h"

using namespace std;

class Cita : public Registro {
    int fecha;
    int hora;
    int dniPaciente;
    int dniDoctor;

    PacienteParticular* pacienteParticular;
    PacienteAsegurado* pacienteAsegurado;
    DoctorGeneral* doctorGeneral;
    DoctorEspecialista* doctorEspecialista;

    char tipoPaciente;
    char tipoDoctor;

    Estado estado;
public:
    Cita();
    Cita(const Cita&);

    int getFecha() const;
    int getHora() const;
    int getDniPaciente() const;
    int getDniDoctor() const;
    char getTipoPaciente() const;
    char getTipoDoctor() const;
    Estado getEstado() const;

    void setFecha(int);
    void setHora(int);
    void setDniPaciente(int);
    void setDniDoctor(int);
    void setPaciente(const PacienteParticular*);
    void setPaciente(const PacienteAsegurado*);
    void setDoctor(const DoctorGeneral*);
    void setDoctor(const DoctorEspecialista*);
    void setEstado(Estado);

    ifstream& leer(ifstream&);
    ofstream& imprimir(ofstream&) const;

    Cita& operator=(const Cita&);
    bool operator<(const Cita&) const;
    Cita& operator!();

    ~Cita();
};

ifstream& operator>>(ifstream&, Cita&);
ofstream& operator<<(ofstream&, const Cita&);

#endif //EJERCICIO01_CITA_H
