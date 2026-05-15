//
// Created by Eric Huiza on 5/8/26.
//

#include "Cita.h"
#include "../doctor/DoctorEspecialista.h"
#include "../doctor/DoctorGeneral.h"
#include "../paciente/PacienteAsegurado.h"
#include "../paciente/PacienteParticular.h"
#include "../funciones.h"
#include <iomanip>

Cita::Cita() {
    fecha = 0;
    hora = 0;
    dniPaciente = 0;
    dniDoctor = 0;
    pacienteParticular = nullptr;
    pacienteAsegurado = nullptr;
    doctorGeneral = nullptr;
    doctorEspecialista = nullptr;
    tipoPaciente = 'N';
    tipoDoctor = 'N';
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

char Cita::getTipoPaciente() const {
    return tipoPaciente;
}

char Cita::getTipoDoctor() const {
    return tipoDoctor;
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

void Cita::setPaciente(const PacienteParticular* paciente) {
    this->pacienteParticular = paciente;
    this->pacienteAsegurado = nullptr;
    this->tipoPaciente = paciente ? 'P' : 'N';
}

void Cita::setPaciente(const PacienteAsegurado* paciente) {
    this->pacienteParticular = nullptr;
    this->pacienteAsegurado = paciente;
    this->tipoPaciente = paciente ? 'A' : 'N';
}

void Cita::setDoctor(const DoctorGeneral* doctor) {
    this->doctorGeneral = doctor;
    this->doctorEspecialista = nullptr;
    this->tipoDoctor = doctor ? 'G' : 'N';
}

void Cita::setDoctor(const DoctorEspecialista* doctor) {
    this->doctorGeneral = nullptr;
    this->doctorEspecialista = doctor;
    this->tipoDoctor = doctor ? 'E' : 'N';
}

void Cita::setEstado(Estado estado) {
    this->estado = estado;
}

Cita& Cita::operator=(const Cita& cita) {
    if (this != &cita) {
        this->setFecha(cita.getFecha());
        this->setHora(cita.getHora());
        this->setDniPaciente(cita.getDniPaciente());
        this->setDniDoctor(cita.getDniDoctor());
        if (cita.tipoPaciente == 'P') this->setPaciente(cita.pacienteParticular);
        else if (cita.tipoPaciente == 'A') this->setPaciente(cita.pacienteAsegurado);
        else this->setPaciente((PacienteParticular*)nullptr);

        if (cita.tipoDoctor == 'G') this->setDoctor(cita.doctorGeneral);
        else if (cita.tipoDoctor == 'E') this->setDoctor(cita.doctorEspecialista);
        else this->setDoctor((DoctorGeneral*)nullptr);

        this->setEstado(cita.getEstado());
    }
    return *this;
}

bool Cita::operator<(const Cita& cita) const {
    if (this->fecha == cita.fecha) {
        return this->hora < cita.hora;
    }
    return this->fecha < cita.fecha;
}

Cita& Cita::operator!() {
    estado = CANCELADA;
    return *this;
}

ifstream& Cita::leer(ifstream& archivo) {
    int anho;
    if (archivo >> anho) {
        archivo.ignore();
        int mes, dia, hora, minuto;
        archivo >> mes;
        archivo.ignore();
        archivo >> dia;
        int fecha = anho * 10000 + mes * 100 + dia;

        archivo.ignore();
        archivo >> hora;
        archivo.ignore();
        archivo >> minuto;
        hora = hora * 100 + minuto;

        int dniPaciente, dniDoctor;
        archivo.ignore();
        archivo >> dniPaciente;
        archivo.ignore();
        archivo >> dniDoctor;
        archivo.ignore();

        char* estado = leerCadena(archivo);

        this->setFecha(fecha);
        this->setHora(hora);
        this->setDniPaciente(dniPaciente);
        this->setDniDoctor(dniDoctor);
        this->setPaciente((PacienteParticular*)nullptr);
        this->setDoctor((DoctorGeneral*)nullptr);
        this->setEstado(convertirEstado(estado));

        delete[] estado;
    }

    return archivo;
}

ofstream& Cita::imprimir(ofstream& os) const {
    const char* estado = "NA";
    if (getEstado() == RESERVADA) estado = "RESERVADA";
    else if (getEstado() == CANCELADA) estado = "CANCELADA";

    const char* nombrePaciente = "NO_ASIGNADO";
    if (tipoPaciente == 'P' && pacienteParticular) {
        nombrePaciente = pacienteParticular->getNombre();
    }
    else if (tipoPaciente == 'A' && pacienteAsegurado) {
        nombrePaciente = pacienteAsegurado->getNombre();
    }

    const char* nombreDoctor = "NO_ASIGNADO";
    if (tipoDoctor == 'G' && doctorGeneral) {
        nombreDoctor = doctorGeneral->getNombre();
    }
    else if (tipoDoctor == 'E' && doctorEspecialista) {
        nombreDoctor = doctorEspecialista->getNombre();
    }

    const char* especialidad = "NA";
    if (tipoDoctor == 'G' && doctorGeneral) {
        especialidad = "GENERAL";
    }
    else if (tipoDoctor == 'E' && doctorEspecialista) {
        switch (doctorEspecialista->getEspecialidad()) {
            case CARDIOLOGIA:
                especialidad = "CARDIOLOGIA";
                break;
            case DERMATOLOGIA:
                especialidad = "DERMATOLOGIA";
                break;
            case NEUROLOGIA:
                especialidad = "NEUROLOGIA";
                break;
            case PEDIATRIA:
                especialidad = "PEDIATRIA";
                break;
            case PSIQUIATRIA:
                especialidad = "PSIQUIATRIA";
                break;
            case TRAUMATOLOGIA:
                especialidad = "TRAUMATOLOGIA";
                break;
            case ENDOCRINOLOGIA:
                especialidad = "ENDOCRINOLOGIA";
                break;
            case GINECOLOGIA:
                especialidad = "GINECOLOGIA";
                break;
            case PSICOLOGIA:
                especialidad = "PSICOLOGIA";
                break;
            case ORTOPEDIA:
                especialidad = "ORTOPEDIA";
                break;
            default:
                especialidad = "GENERAL";
                break;
        }
    }

    os << right << setfill('0') << setw(8) << getFecha() << setfill(' ') << " ";
    os << right << setfill('0') << setw(4) << getHora() << setfill(' ') << " ";
    os << right << setw(10) << getDniPaciente() << " ";
    os << left << setw(20) << nombrePaciente;
    os << right << setw(10) << getDniDoctor() << " ";
    os << left << setw(20) << nombreDoctor;
    os << left << setw(16) << especialidad;
    os << left << setw(12) << estado;

    return os;
}

Cita::~Cita() {
}

ifstream& operator>>(ifstream& archivo, Cita& cita) {
    return cita.leer(archivo);
}

ofstream& operator<<(ofstream& os, const Cita& cita) {
    return cita.imprimir(os);
}
