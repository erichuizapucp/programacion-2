//
// Created by Eric Huiza on 5/8/26.
//

#include "Clinica.h"

Clinica::Clinica() {
    pacientes = nullptr;
    doctores = nullptr;
    citas = nullptr;

    numCitas = 0;
    numDoctors = 0;
    numPacientes = 0;
    capCitas = 0;
    capDoctor = 0;
    capPaciente = 0;
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

void Clinica::procesarCitas() {
    for (int i = 0; i < numCitas; i++) {
        Cita& cita = citas[i];

        int dniPaciente = cita.getDniPaciente();
        int dniDoctor = cita.getDniDoctor();

        const Paciente* paciente = obtenerPacientePorDni(dniPaciente);
        const Doctor* doctor = obtenerDoctorPorDni(dniDoctor);

        cita.setPaciente(paciente);
        cita.setDoctor(doctor);
    }
}

void Clinica::cancelarCita(int indice) {
    !citas[indice];
}

void Clinica::generarReporte(const char* nombreArchivo) const {
    ofstream archivo(nombreArchivo, ios::out);
    archivo << *this;
}

const Paciente* Clinica::obtenerPacientePorDni(int dni) const {
    for (int i = 0; i < numPacientes; i++) {
        if (pacientes[i].getDni() == dni) {
            return &pacientes[i];
        }
    }
    return nullptr;
}

const Doctor* Clinica::obtenerDoctorPorDni(int dni) const {
    for (int i = 0; i < numDoctors; i++) {
        if (doctores[i].getDni() == dni) {
            return &doctores[i];
        }
    }
    return nullptr;
}

void Clinica::insertarOrdenado(const Cita& nuevaCita) {
    int pos = 0;
    while (pos < numCitas && !(nuevaCita < citas[pos])) {
        pos++;
    }

    for (int i = numCitas; i > pos; i--) {
        citas[i] = citas[i - 1];
    }

    citas[pos] = nuevaCita;
    numCitas++;
}

Clinica& Clinica::operator+=(const Paciente& paciente) {
    if (numPacientes == capPaciente) {
        incrementarPacientes();
    }
    pacientes[numPacientes++] = paciente;
    return *this;
}

Clinica& Clinica::operator+=(const Doctor& doctor) {
    if (numDoctors == capDoctor) {
        incrementarDoctores();
    }
    doctores[numDoctors++] = doctor;
    return *this;
}

Clinica& Clinica::operator+=(const Cita& cita) {
    if (numCitas == capCitas) {
        incrementarCitas();
    }
    insertarOrdenado(cita);
    return *this;
}

void Clinica::incrementarPacientes() {
    Paciente* aux;
    capPaciente += 5;

    if (pacientes == nullptr) { // primer incremento
        pacientes = new Paciente[capPaciente];
    }
    else {
        aux = new Paciente[capPaciente];
        for (int i = 0; i < numPacientes; i++) {
            aux[i] = pacientes[i];
        }
        delete[] pacientes;
        pacientes = aux;
    }
}

void Clinica::incrementarDoctores() {
    Doctor* aux;
    capDoctor += 5;
    if (doctores == nullptr) {
        doctores = new Doctor[capDoctor];
    }
    else {
        aux = new Doctor[capDoctor];
        for (int i = 0; i < numDoctors; i++) {
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
        for (int i = 0; i < numCitas; i++) {
            aux[i] = citas[i];
        }
        delete[] citas;
        citas = aux;
    }
}

int Clinica::getNumCitas() const {
    return numCitas;
}
Cita* Clinica::getCita(int indice) const {
    return &citas[indice];
}

Clinica::~Clinica() {
    delete[] pacientes;
    delete[] doctores;
    delete[] citas;
}

ofstream& operator<<(ofstream& os, const Clinica& clinica) {
    for (int i = 0; i < clinica.getNumCitas(); i++) {
        os << *clinica.getCita(i) << endl;
    }
    return os;
}