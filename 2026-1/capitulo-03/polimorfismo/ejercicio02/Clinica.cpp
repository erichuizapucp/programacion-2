//
// Created by Eric Huiza on 5/8/26.
//

#include "Clinica.h"
#include <iomanip>

Clinica::Clinica() {
    pacientes = nullptr;
    doctores = nullptr;
    citas = nullptr;

    numCitas = 0;
    numDoctores = 0;
    numPacientes = 0;

    capCitas = 0;
    capDoctores = 0;
    capPacientes = 0;
}

void Clinica::cargarPacientes(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    char tipo;
    while (archivo >> tipo) {
        archivo.ignore();

        Paciente* paciente = nullptr;
        if (tipo == 'P') {
            paciente = new PacienteParticular();
        }
        else if (tipo == 'A') {
            paciente = new PacienteAsegurado();
        }

        if (paciente && (archivo >> *paciente)) {
            *this += paciente;
        }
        else {
            delete paciente;
        }
    }
}

void Clinica::cargarDoctores(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    char tipo;
    while (archivo >> tipo) {
        archivo.ignore();

        Doctor* doctor = nullptr;
        if (tipo == 'G') {
            doctor = new DoctorGeneral();
        }
        else if (tipo == 'E') {
            doctor = new DoctorEspecialista();
        }

        if (doctor && (archivo >> *doctor)) {
            *this += doctor;
        }
        else {
            delete doctor;
        }
    }
}

void Clinica::cargarCitas(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    char tipo;
    while (archivo >> tipo) {
        archivo.ignore();

        Cita* cita = nullptr;
        if (tipo == 'R') {
            cita = new CitaPresencial();
        }
        else if (tipo == 'V') {
            cita = new CitaVirtual();
        }

        if (cita && (archivo >> *cita)) {
            *this += cita;
        }
        else {
            delete cita;
        }
    }
}

void Clinica::procesarCitas() const {
    for (int i = 0; i < numCitas; i++) {
        procesarCita(*citas[i]);
    }
}

void Clinica::asignarPacienteYDoctor(Cita& cita) const {
    const Paciente* paciente = obtenerPacientePorDni(cita.getDniPaciente());
    const Doctor* doctor = obtenerDoctorPorDni(cita.getDniDoctor());

    cita.setPaciente(paciente);
    cita.setDoctor(doctor);
}

void Clinica::procesarCita(Cita& cita) const {
    asignarPacienteYDoctor(cita);
}

void Clinica::cancelarCita(int indice) const {
    if (indice >= 0 && indice < numCitas) {
        !(*citas[indice]);
    }
}

void Clinica::generarReporte(const char* nombreArchivo) const {
    ofstream archivo(nombreArchivo, ios::out);
    archivo << *this;
}

const Paciente* Clinica::obtenerPacientePorDni(int dni) const {
    for (int i = 0; i < numPacientes; i++) {
        if (pacientes[i]->getDni() == dni) {
            return pacientes[i];
        }
    }
    return nullptr;
}

const Doctor* Clinica::obtenerDoctorPorDni(int dni) const {
    for (int i = 0; i < numDoctores; i++) {
        if (doctores[i]->getDni() == dni) {
            return doctores[i];
        }
    }
    return nullptr;
}

void Clinica::insertarOrdenado(Cita* nuevaCita) {
    int pos = 0;
    while (pos < numCitas && !(*nuevaCita < *citas[pos])) {
        pos++;
    }

    for (int i = numCitas; i > pos; i--) {
        citas[i] = citas[i - 1];
    }
    citas[pos] = nuevaCita;
    numCitas++;
}

Clinica& Clinica::operator+=(Paciente* paciente) {
    if (numPacientes == capPacientes) {
        incrementarPacientes();
    }
    pacientes[numPacientes++] = paciente;
    return *this;
}

Clinica& Clinica::operator+=(Doctor* doctor) {
    if (numDoctores == capDoctores) {
        incrementarDoctores();
    }
    doctores[numDoctores++] = doctor;
    return *this;
}

Clinica& Clinica::operator+=(Cita* cita) {
    if (numCitas == capCitas) {
        incrementarCitas();
    }
    insertarOrdenado(cita);
    return *this;
}

void Clinica::incrementarPacientes() {
    capPacientes += 5;
    Paciente** aux = new Paciente*[capPacientes];

    for (int i = 0; i < numPacientes; i++) {
        aux[i] = pacientes[i];
    }

    delete[] pacientes;
    pacientes = aux;
}

void Clinica::incrementarDoctores() {
    capDoctores += 5;
    Doctor** aux = new Doctor*[capDoctores];

    for (int i = 0; i < numDoctores; i++) {
        aux[i] = doctores[i];
    }

    delete[] doctores;
    doctores = aux;
}

void Clinica::incrementarCitas() {
    capCitas += 5;
    Cita** aux = new Cita*[capCitas];

    for (int i = 0; i < numCitas; i++) {
        aux[i] = citas[i];
    }

    delete[] citas;
    citas = aux;
}

int Clinica::getNumCitas() const {
    return numCitas;
}

Clinica::~Clinica() {
    for (int i = 0; i < numPacientes; i++) {
        delete pacientes[i];
    }
    for (int i = 0; i < numDoctores; i++) {
        delete doctores[i];
    }
    for (int i = 0; i < numCitas; i++) {
        delete citas[i];
    }

    delete[] pacientes;
    delete[] doctores;
    delete[] citas;
}

ofstream& operator<<(ofstream& os, const Clinica& clinica) {
    os << "CITAS" << endl;
    os << left
       << setw(8) << "FECHA" << " "
       << setw(4) << "HORA" << " "
       << setw(10) << "DNI_PAC" << " "
       << setw(20) << "NOMBRE_PAC"
       << setw(10) << "DNI_DOC" << " "
       << setw(20) << "NOMBRE_DOC"
       << setw(16) << "ESPECIALIDAD"
       << setw(12) << "ESTADO"
       << setw(20) << "ATENCION"
       << "REFERENCIA" << endl;

    for (int i = 0; i < clinica.numCitas; i++) {
        os << *clinica.citas[i] << endl;
    }

    return os;
}
