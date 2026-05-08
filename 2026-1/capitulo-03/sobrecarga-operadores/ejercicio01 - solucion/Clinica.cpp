//
// Created by Eric Huiza on 5/8/26.
//

#include "Clinica.h"

Clinica::Clinica() {
    pacientes = nullptr;
    doctores = nullptr;
    citas = nullptr;

    numeroCitas = 0;
    numeroDoctores = 0;
    numeroPacientes = 0;

    capCitas = 0;
    capDoctores = 0;
    capPacientes = 0;
}

Clinica::Clinica(const Clinica& origin) : Clinica() {
    *this = origin;
}

void Clinica::cargarPacientes(const char* nombreArchivo) {
    Paciente paciente;
    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> paciente) {
        *this += paciente;
    }
}

void Clinica::cargarDoctores(const char* nombreArchivo) {
    Doctor doctor;
    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> doctor) {
        *this += doctor;
    }
}

void Clinica::cargarCitas(const char* nombreArchivo) {
    Cita cita; // dato, fila

    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> cita) { // lee una fila en el archivo
        *this += cita;
    }
}

void Clinica::procesarCitas() {
    for (int i = 0; i < numeroCitas; i++) {
        int dniPaciente = citas[i].getDniPaciente();
        int dniDoctor = citas[i].getDniDoctor();

        citas[i].setPaciente(obtenerPacientePorDni(dniPaciente));
        citas[i].setDoctor(obtenerDoctorPorDni(dniDoctor));
    }
}

Paciente* Clinica::obtenerPacientePorDni(int dni) const {
    for (int i = 0; numeroPacientes; i++) {
        if (pacientes[i].getDni() == dni) {
            return &pacientes[i];
        }
    }
    return nullptr;
}

Doctor* Clinica::obtenerDoctorPorDni(int dni) const {
    for (int i = 0; numeroDoctores; i++) {
        if (doctores[i].getDni() == dni) {
            return &doctores[i];
        }
    }
    return nullptr;
}

void Clinica::cancelarCita(int idCita) {
    if (idCita >= 0 && idCita < numeroCitas) {
        !citas[idCita];
    }
}
void Clinica::generarReporte(const char* nombreArchivo) const {
    ofstream archivo(nombreArchivo, ios::out);
    archivo << *this;
}

Clinica& Clinica::operator+=(const Paciente& paciente) {
    if (numeroPacientes == capPacientes) {
        incrementarPacientes();
    }
    pacientes[numeroPacientes] = paciente;
    numeroPacientes++;
    return *this;
}

Clinica& Clinica::operator+=(const Doctor& doctor) {
    if (numeroDoctores == capDoctores) {
        incrementarDoctores();
    }
    doctores[numeroDoctores] = doctor;
    numeroDoctores++;
    return *this;
}

Clinica& Clinica::operator+=(const Cita& cita) {
    if (numeroCitas == capCitas) {
        incrementarCitas();
    }
    citas[numeroCitas++] = cita;
    return *this;
}

void Clinica::incrementarPacientes() {
    Paciente* aux;
    capPacientes += 5;

    if (pacientes == nullptr) { // primer incremento
        pacientes = new Paciente[capPacientes];
    }
    else {
        aux = new Paciente[capPacientes];
        for (int i = 0; i < numeroPacientes; i++) {
            aux[i] = pacientes[i];
        }
        delete[] pacientes;
        pacientes = aux;
    }
}

void Clinica::incrementarDoctores() {
    Doctor* aux;
    capDoctores += 5;
    if (doctores == nullptr) {
        doctores = new Doctor[capDoctores];
    }
    else {
        aux = new Doctor[capDoctores];
        for (int i = 0; i < numeroDoctores; i++) {
            aux[i] = doctores[i];
        }
        delete[] doctores;
        doctores = aux;
    }
}

void Clinica::incrementarCitas() {
    Cita* aux;
    capCitas += 5;
    if (citas == nullptr) {
        citas = new Cita[capCitas];
    }
    else {
        aux = new Cita[capCitas];
        for (int i = 0; i < numeroCitas; i++) {
            aux[i] = citas[i];
        }
        delete[] citas;
        citas = aux;
    }
}

int Clinica::getNumeroCitas() const {
    return numeroCitas;
}

Cita* Clinica::getCita(int index) const {
    if (index >= 0 && index < numeroCitas) {
        return &citas[index];
    }
    return nullptr;
}

Clinica::~Clinica() {
    delete[] citas;
    delete[] pacientes;
    delete[] doctores;
}

ofstream& operator<<(ofstream& os, const Clinica& clinica) {
    for (int i = 0; i < clinica.getNumeroCitas(); i++) {
        os << *clinica.getCita(i) << endl;
    }

    return os;
}