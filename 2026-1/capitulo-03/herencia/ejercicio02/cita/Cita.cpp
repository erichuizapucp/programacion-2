//
// Created by Eric Huiza on 5/8/26.
//

#include "Cita.h"

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
    delete this->pacienteParticular;
    this->pacienteAsegurado = nullptr;

    if (paciente) {
        this->pacienteParticular = new PacienteParticular();
        *this->pacienteParticular = *paciente;
        this->tipoPaciente = 'P';
    }
    else {
        this->pacienteParticular = nullptr;
        this->tipoPaciente = 'P';
    }
}

void Cita::setPaciente(const PacienteAsegurado* paciente) {
    delete this->pacienteAsegurado;
    this->pacienteParticular = nullptr;

    if (paciente) {
        this->pacienteAsegurado = new PacienteAsegurado();
        *this->pacienteAsegurado = *paciente;
        this->tipoPaciente = 'A';
    }
    else {
        this->pacienteAsegurado = nullptr;
        this->tipoPaciente = 'A';
    }

}

void Cita::setDoctor(const DoctorGeneral* doctor) {
    delete this->doctorGeneral;
    this->doctorEspecialista = nullptr;

    if (doctor) {
        this->doctorGeneral = new DoctorGeneral();
        *this->doctorGeneral = *doctor;
        this->tipoDoctor = 'G';
    }
    else {
        this->doctorGeneral = nullptr;
        this->tipoDoctor = 'G';
    }

}

void Cita::setDoctor(const DoctorEspecialista* doctor) {
    delete this->doctorEspecialista;
    this->doctorGeneral = nullptr;

    if (doctor) {
        this->doctorEspecialista = new DoctorEspecialista();
        *this->doctorEspecialista = *doctor;
        this->tipoDoctor = 'E';
    }
    else {
        this->doctorEspecialista = nullptr;
        this->tipoDoctor = 'E';
    }
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

        if (cita.tipoPaciente == 'P') {
            this->setPaciente(cita.pacienteParticular);
        }
        else {
            this->setPaciente(cita.pacienteAsegurado);
        }

        if (cita.tipoDoctor == 'G') {
            this->setDoctor(cita.doctorGeneral);
        }
        else {
            this->setDoctor(cita.doctorEspecialista);
        }

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
        this->setEstado(convertirEstado(estado));

        delete[] estado;
    }

    return archivo;
}

ofstream& Cita::imprimir(ofstream& os) const {
    const char* estadoCita;
    if (getEstado() == RESERVADA) {
        estadoCita = "RESERVADA";
    }
    else {
        estadoCita = "CANCELADA";
    }

    const char* nombrePaciente;
    if (tipoPaciente == 'P') {
        nombrePaciente = pacienteParticular->getNombre();
    }
    else {
        nombrePaciente = pacienteAsegurado->getNombre();
    }

    const char* nombreDoctor;
    if (tipoDoctor == 'G') {
        nombreDoctor = doctorGeneral->getNombre();
    }
    else {
        nombreDoctor = doctorEspecialista->getNombre();
    }

    const char* especialidad;
    if (tipoDoctor == 'G') {
        especialidad = "GENERAL";
    }
    else {
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
    os << left << setw(12) << estadoCita;

    return os;
}

Cita::~Cita() {
    delete pacienteParticular;
    delete pacienteAsegurado;
    delete doctorGeneral;
    delete doctorEspecialista;
}

ifstream& operator>>(ifstream& archivo, Cita& cita) {
    return cita.leer(archivo);
}

ofstream& operator<<(ofstream& os, const Cita& cita) {
    return cita.imprimir(os);
}
