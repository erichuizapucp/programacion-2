//
// Created by Eric Huiza on 5/8/26.
//

#include "Cita.h"
#include "Paciente.h"
#include "funciones.h"

Cita::Cita() {
    fecha = 0;
    hora = 0;
    dniPaciente = 0;
    dniDoctor = 0;
    paciente = nullptr;
    doctor = nullptr;
    estado = NA;
}

Cita::Cita(const Cita& origin) : Cita() {
    *this = origin;
}

int Cita::getFecha() const {
    return fecha;
}

int Cita::getHora() const {
    return hora;
}

int Cita::getDniPaciente() const {
    return dniPaciente;
}

int Cita::getDniDoctor() const {
    return dniDoctor;
}

Paciente* Cita::getPaciente() const {
    return paciente;
}

Doctor* Cita::getDoctor() const {
    return doctor;
}

Estado Cita::getEstado() const {
    return estado;
}

void Cita::setFecha(int fecha) {
    this->fecha = fecha;
}

void Cita::setHora(int hora) {
    this->hora = hora;
}

void Cita::setDniPaciente(int dniPaciente) {
    this->dniPaciente = dniPaciente;
}

void Cita::setDniDoctor(int dniDoctor) {
    this->dniDoctor = dniDoctor;
}

void Cita::setPaciente(const Paciente* paciente) {
    delete this->paciente;
    if (paciente == nullptr) {
        this->paciente = nullptr;
        return;
    }
    this->paciente = new Paciente(*paciente);
}

void Cita::setDoctor(const Doctor* doctor) {
    delete this->doctor;
    if (doctor == nullptr) {
        this->doctor = nullptr;
        return;
    }
    this->doctor = new Doctor(*doctor);
}

void Cita::setEstado(Estado estado) {
    this->estado = estado;
}

Cita& Cita::operator=(const Cita& origin) {
    if (this == &origin) {
        return *this;
    }

    this->setFecha(origin.getFecha());
    this->setHora(origin.getHora());
    this->setDniPaciente(origin.getDniPaciente());
    this->setDniDoctor(origin.getDniDoctor());
    this->setPaciente(origin.getPaciente());
    this->setDoctor(origin.getDoctor());
    this->setEstado(origin.getEstado());

    return *this;
}

bool Cita::operator<(const Cita& cita) const {
    if (fecha == cita.fecha) {
        return hora < cita.hora;
    }
    return fecha < cita.fecha;
}

Cita& Cita::operator!() {
    estado = CANCELADA;
    return *this;
}

Cita::~Cita() {
    delete this->paciente;
    delete this->doctor;
}

ifstream& operator>>(ifstream& archivo, Cita& cita) {
    int anho;
    if (archivo >> anho) {
        int fecha;
        int dniPaciente;
        int dniDoctor;

        archivo.ignore();
        int mes, dia, hora, minuto;
        archivo >> mes;
        archivo.ignore();
        archivo >> dia;
        fecha = anho * 10000 + mes * 100 + dia;

        archivo.ignore();
        archivo >> hora;
        archivo.ignore();
        archivo >> minuto;
        hora = hora * 100 + minuto;

        archivo.ignore();
        archivo >> dniPaciente;
        archivo.ignore();
        archivo >> dniDoctor;
        archivo.ignore();

        char* estado = leerCadena(archivo, '\n');

        cita.setFecha(fecha);
        cita.setHora(hora);
        cita.setDniPaciente(dniPaciente);
        cita.setDniDoctor(dniDoctor);
        cita.setEstado(convertirEstado(estado));
        delete[] estado;

        return archivo;
    }

    return archivo;
}

ofstream& operator<<(ofstream& os, const Cita& cita) {
    os << "==============================" << endl;
    os << "DATOS DEL CITA" << endl;
    os << "------------------------------" << endl;
    imprimirFecha(os, cita.getFecha());
    imprimirHora(os, cita.getHora());
    imprimirEstado(os, cita.getEstado());
    os << endl;
    os << "------------------------------" << endl;
    os << "DATOS DEL PACIENTE" << endl;
    os << "------------------------------" << endl;
    os << *cita.getPaciente() << endl;
    os << "------------------------------" << endl;
    os << "DATOS DEL DOCTOR" << endl;
    os << "------------------------------" << endl;
    os << *cita.getDoctor() << endl;
    os << "------------------------------" << endl;
    os << "==============================" << endl;

    return os;
}
