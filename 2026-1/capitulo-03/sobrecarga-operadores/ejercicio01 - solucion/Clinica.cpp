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
    Cita cita;

    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> cita) {
        *this += cita;
    }
}

void Clinica::procesarCitas() const {
    for (int i = 0; i < numeroCitas; i++) {
        Cita& cita = citas[i];

        int dniPaciente = cita.getDniPaciente();
        int dniDoctor = cita.getDniDoctor();

        cita.setPaciente(obtenerPacientePorDni(dniPaciente));
        cita.setDoctor(obtenerDoctorPorDni(dniDoctor));
    }
}

void Clinica::insertarOrdenado(const Cita& nuevaCita) {
    int pos = 0;
    while (pos < numeroCitas && !(nuevaCita < citas[pos])) {
        pos++;
    }

    for (int i = numeroCitas; i > pos; i--) {
        citas[i] = citas[i - 1];
    }

    citas[pos] = nuevaCita;
    numeroCitas++;
}

Paciente* Clinica::obtenerPacientePorDni(int dni) const {
    for (int i = 0; i < numeroPacientes; i++) {
        if (pacientes[i].getDni() == dni) {
            return &pacientes[i];
        }
    }
    return nullptr;
}

Doctor* Clinica::obtenerDoctorPorDni(int dni) const {
    for (int i = 0; i < numeroDoctores; i++) {
        if (doctores[i].getDni() == dni) {
            return &doctores[i];
        }
    }
    return nullptr;
}

void Clinica::cancelarCita(int idCita) const {
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
    pacientes[numeroPacientes++] = paciente;
    return *this;
}

Clinica& Clinica::operator+=(const Doctor& doctor) {
    if (numeroDoctores == capDoctores) {
        incrementarDoctores();
    }
    doctores[numeroDoctores++] = doctor;
    return *this;
}

Clinica& Clinica::operator+=(const Cita& cita) {
    if (numeroCitas == capCitas) {
        incrementarCitas();
    }
    insertarOrdenado(cita);
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
        const Cita& cita = *clinica.getCita(i);
        os << cita << endl;
    }

    return os;
}