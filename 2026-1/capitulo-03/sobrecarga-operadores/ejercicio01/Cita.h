//
// Created by Eric Huiza on 5/8/26.
//

#ifndef EJERCICIO01_CITA_H
#define EJERCICIO01_CITA_H
#include "Doctor.h"
#include "Paciente.h"

#include <fstream>

using namespace std;

class Cita {
    int fecha;
    int hora;
    int dniPaciente;
    int dniDoctor;
    const Paciente* paciente;
    const Doctor* doctor;
    Estado estado;
public:
    Cita();
    Cita(const Cita&);

    int getFecha() const;
    int getHora() const;
    int getDniPaciente() const;
    int getDniDoctor() const;
    const Paciente* getPaciente() const;
    const Doctor* getDoctor() const;
    Estado getEstado() const;

    void setFecha(int);
    void setHora(int);
    void setDniPaciente(int);
    void setDniDoctor(int);
    void setPaciente(const Paciente*);
    void setDoctor(const Doctor*);
    void setEstado(Estado);

    Cita& operator=(const Cita&);
    bool operator<(const Cita&) const;
    Cita& operator!();

    ~Cita();
};

ifstream& operator>>(ifstream&, Cita&);
ofstream& operator<<(ofstream&, const Cita&);

#endif //EJERCICIO01_CITA_H
