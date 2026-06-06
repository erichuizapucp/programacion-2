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

    Paciente* paciente;
    Doctor* doctor;

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
    void setPaciente(const Paciente*);
    void setDoctor(const Doctor*);
    void setEstado(Estado);

    ifstream& leer(ifstream&) override;
    ofstream& imprimir(ofstream&) const override;

    Cita& operator=(const Cita&);
    bool operator<(const Cita&) const;
    Cita& operator!();

    virtual ~Cita();
};

#endif //EJERCICIO01_CITA_H
