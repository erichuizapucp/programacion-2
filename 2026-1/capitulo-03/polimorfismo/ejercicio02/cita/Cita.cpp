//
// Created by Eric Huiza on 5/8/26.
//

#include "Cita.h"

Cita::Cita() {
    fecha = 0;
    hora = 0;
    dniPaciente = 0;
    dniDoctor = 0;

    paciente = nullptr;
    doctor = nullptr;

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

void Cita::setPaciente(const Paciente* paciente) {
    delete this->paciente;

    if (paciente) {
        if (const auto* particular = dynamic_cast<const PacienteParticular*>(paciente)) {
            auto* nuevoPaciente = new PacienteParticular();
            *nuevoPaciente = *particular;
            this->paciente = nuevoPaciente;
            this->tipoPaciente = 'P';
        }
        else {
            const auto* asegurado = dynamic_cast<const PacienteAsegurado*>(paciente);
            auto* nuevoPaciente = new PacienteAsegurado();
            if (asegurado) {
                *nuevoPaciente = *asegurado;
            }
            this->paciente = nuevoPaciente;
            this->tipoPaciente = 'A';
        }
    }
    else {
        this->paciente = nullptr;
        this->tipoPaciente = 'N';
    }
}

void Cita::setDoctor(const Doctor* doctor) {
    delete this->doctor;

    if (doctor) {
        if (const auto* general = dynamic_cast<const DoctorGeneral*>(doctor)) {
            auto* nuevoDoctor = new DoctorGeneral();
            *nuevoDoctor = *general;
            this->doctor = nuevoDoctor;
            this->tipoDoctor = 'G';
        }
        else {
            const auto* especialista = dynamic_cast<const DoctorEspecialista*>(doctor);
            auto* nuevoDoctor = new DoctorEspecialista();
            if (especialista) {
                *nuevoDoctor = *especialista;
            }
            this->doctor = nuevoDoctor;
            this->tipoDoctor = 'E';
        }
    }
    else {
        this->doctor = nullptr;
        this->tipoDoctor = 'N';
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

        this->setPaciente(cita.paciente);
        this->setDoctor(cita.doctor);

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

    const char *nombrePaciente = paciente ? paciente->getNombre() : "N/A";
    const char* nombreDoctor = doctor ? doctor->getNombre() : "N/A";

    const char* especialidad;
    if (!doctor) {
        especialidad = "N/A";
    }
    else if (tipoDoctor == 'G') {
        especialidad = "GENERAL";
    }
    else {
        switch (doctor->getEspecialidad()) {
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
    delete paciente;
    delete doctor;
}
