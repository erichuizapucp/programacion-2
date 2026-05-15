//
// Created by Eric Huiza on 5/8/26.
//

#include "Clinica.h"
#include <iomanip>

Clinica::Clinica() {
    pacientesParticulares = nullptr;
    pacientesAsegurados = nullptr;
    doctoresGenerales = nullptr;
    doctoresEspecialistas = nullptr;
    citasPresenciales = nullptr;
    citasVirtuales = nullptr;

    numCitasPresenciales = 0;
    numCitasVirtuales = 0;
    numDoctoresGenerales = 0;
    numDoctoresEspecialistas = 0;
    numPacientesParticulares = 0;
    numPacientesAsegurados = 0;

    capCitasPresenciales = 0;
    capCitasVirtuales = 0;
    capDoctoresGenerales = 0;
    capDoctoresEspecialistas = 0;
    capPacientesParticulares = 0;
    capPacientesAsegurados = 0;
}

void Clinica::cargarPacientes(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    char tipo;
    while (archivo >> tipo) {
        archivo.ignore();
        if (tipo == 'P') {
            PacienteParticular paciente;
            archivo >> paciente;
            *this += paciente;
        }
        else if (tipo == 'A') {
            PacienteAsegurado paciente;
            archivo >> paciente;
            *this += paciente;
        }
    }
}

void Clinica::cargarDoctores(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    char tipo;
    while (archivo >> tipo) {
        archivo.ignore();
        if (tipo == 'G') {
            DoctorGeneral doctor;
            archivo >> doctor;
            *this += doctor;
        }
        else if (tipo == 'E') {
            DoctorEspecialista doctor;
            archivo >> doctor;
            *this += doctor;
        }
    }
}

void Clinica::cargarCitas(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    char tipo;
    while (archivo >> tipo) {
        archivo.ignore();
        if (tipo == 'R') {
            CitaPresencial cita;
            archivo >> cita;
            *this += cita;
        }
        else if (tipo == 'V') {
            CitaVirtual cita;
            archivo >> cita;
            *this += cita;
        }
    }
}

void Clinica::procesarCitas() const {
    for (int i = 0; i < numCitasPresenciales; i++) {
        procesarCita(citasPresenciales[i]);
    }

    for (int i = 0; i < numCitasVirtuales; i++) {
        procesarCita(citasVirtuales[i]);
    }
}

void Clinica::asignarPacienteYDoctor(Cita& cita) const {
    int dniPaciente = cita.getDniPaciente();
    int dniDoctor = cita.getDniDoctor();

    const PacienteParticular* pacienteParticular = obtenerPacienteParticularPorDni(dniPaciente);
    const PacienteAsegurado* pacienteAsegurado = obtenerPacienteAseguradoPorDni(dniPaciente);
    const DoctorGeneral* doctorGeneral = obtenerDoctorGeneralPorDni(dniDoctor);
    const DoctorEspecialista* doctorEspecialista = obtenerDoctorEspecialistaPorDni(dniDoctor);

    if (pacienteParticular) {
        cita.setPaciente(pacienteParticular);
    }
    else {
        cita.setPaciente(pacienteAsegurado);
    }

    if (doctorGeneral) {
        cita.setDoctor(doctorGeneral);
    }
    else {
        cita.setDoctor(doctorEspecialista);
    }
}

void Clinica::procesarCita(CitaPresencial& cita) const {
    asignarPacienteYDoctor(cita);
}

void Clinica::procesarCita(CitaVirtual& cita) const {
    asignarPacienteYDoctor(cita);
}

void Clinica::cancelarCitaPresencial(int indice) const {
    if (indice >= 0 && indice < numCitasPresenciales) {
        !citasPresenciales[indice];
    }
}

void Clinica::cancelarCitaVirtual(int indice) const {
    if (indice >= 0 && indice < numCitasVirtuales) {
        !citasVirtuales[indice];
    }
}

void Clinica::generarReporte(const char* nombreArchivo) const {
    ofstream archivo(nombreArchivo, ios::out);
    archivo << *this;
}

const PacienteParticular* Clinica::obtenerPacienteParticularPorDni(int dni) const {
    for (int i = 0; i < numPacientesParticulares; i++) {
        if (pacientesParticulares[i].getDni() == dni) {
            return &pacientesParticulares[i];
        }
    }
    return nullptr;
}

const PacienteAsegurado* Clinica::obtenerPacienteAseguradoPorDni(int dni) const {
    for (int i = 0; i < numPacientesAsegurados; i++) {
        if (pacientesAsegurados[i].getDni() == dni) {
            return &pacientesAsegurados[i];
        }
    }
    return nullptr;
}

const DoctorGeneral* Clinica::obtenerDoctorGeneralPorDni(int dni) const {
    for (int i = 0; i < numDoctoresGenerales; i++) {
        if (doctoresGenerales[i].getDni() == dni) {
            return &doctoresGenerales[i];
        }
    }
    return nullptr;
}

const DoctorEspecialista* Clinica::obtenerDoctorEspecialistaPorDni(int dni) const {
    for (int i = 0; i < numDoctoresEspecialistas; i++) {
        if (doctoresEspecialistas[i].getDni() == dni) {
            return &doctoresEspecialistas[i];
        }
    }
    return nullptr;
}

void Clinica::insertarOrdenado(const CitaPresencial& nuevaCita) {
    int pos = 0;
    while (pos < numCitasPresenciales && !(nuevaCita < citasPresenciales[pos])) {
        pos++;
    }

    for (int i = numCitasPresenciales; i > pos; i--) {
        citasPresenciales[i] = citasPresenciales[i - 1];
    }

    citasPresenciales[pos] = nuevaCita;
    numCitasPresenciales++;
}

void Clinica::insertarOrdenado(const CitaVirtual& nuevaCita) {
    int pos = 0;
    while (pos < numCitasVirtuales && !(nuevaCita < citasVirtuales[pos])) {
        pos++;
    }

    for (int i = numCitasVirtuales; i > pos; i--) {
        citasVirtuales[i] = citasVirtuales[i - 1];
    }

    citasVirtuales[pos] = nuevaCita;
    numCitasVirtuales++;
}

Clinica& Clinica::operator+=(const PacienteParticular& paciente) {
    if (numPacientesParticulares == capPacientesParticulares) {
        incrementarPacientesParticulares();
    }
    pacientesParticulares[numPacientesParticulares++] = paciente;
    return *this;
}

Clinica& Clinica::operator+=(const PacienteAsegurado& paciente) {
    if (numPacientesAsegurados == capPacientesAsegurados) {
        incrementarPacientesAsegurados();
    }
    pacientesAsegurados[numPacientesAsegurados++] = paciente;
    return *this;
}

Clinica& Clinica::operator+=(const DoctorGeneral& doctor) {
    if (numDoctoresGenerales == capDoctoresGenerales) {
        incrementarDoctoresGenerales();
    }
    doctoresGenerales[numDoctoresGenerales++] = doctor;
    return *this;
}

Clinica& Clinica::operator+=(const DoctorEspecialista& doctor) {
    if (numDoctoresEspecialistas == capDoctoresEspecialistas) {
        incrementarDoctoresEspecialistas();
    }
    doctoresEspecialistas[numDoctoresEspecialistas++] = doctor;
    return *this;
}

Clinica& Clinica::operator+=(const CitaPresencial& cita) {
    if (numCitasPresenciales == capCitasPresenciales) {
        incrementarCitasPresenciales();
    }
    insertarOrdenado(cita);
    return *this;
}

Clinica& Clinica::operator+=(const CitaVirtual& cita) {
    if (numCitasVirtuales == capCitasVirtuales) {
        incrementarCitasVirtuales();
    }
    insertarOrdenado(cita);
    return *this;
}

void Clinica::incrementarPacientesParticulares() {
    PacienteParticular* aux;
    capPacientesParticulares += 5;

    if (pacientesParticulares == nullptr) {
        pacientesParticulares = new PacienteParticular[capPacientesParticulares];
    }
    else {
        aux = new PacienteParticular[capPacientesParticulares];
        for (int i = 0; i < numPacientesParticulares; i++) {
            aux[i] = pacientesParticulares[i];
        }
        delete[] pacientesParticulares;
        pacientesParticulares = aux;
    }
}

void Clinica::incrementarPacientesAsegurados() {
    PacienteAsegurado* aux;
    capPacientesAsegurados += 5;

    if (pacientesAsegurados == nullptr) {
        pacientesAsegurados = new PacienteAsegurado[capPacientesAsegurados];
    }
    else {
        aux = new PacienteAsegurado[capPacientesAsegurados];
        for (int i = 0; i < numPacientesAsegurados; i++) {
            aux[i] = pacientesAsegurados[i];
        }
        delete[] pacientesAsegurados;
        pacientesAsegurados = aux;
    }
}

void Clinica::incrementarDoctoresGenerales() {
    DoctorGeneral* aux;
    capDoctoresGenerales += 5;

    if (doctoresGenerales == nullptr) {
        doctoresGenerales = new DoctorGeneral[capDoctoresGenerales];
    }
    else {
        aux = new DoctorGeneral[capDoctoresGenerales];
        for (int i = 0; i < numDoctoresGenerales; i++) {
            aux[i] = doctoresGenerales[i];
        }
        delete[] doctoresGenerales;
        doctoresGenerales = aux;
    }
}

void Clinica::incrementarDoctoresEspecialistas() {
    DoctorEspecialista* aux;
    capDoctoresEspecialistas += 5;

    if (doctoresEspecialistas == nullptr) {
        doctoresEspecialistas = new DoctorEspecialista[capDoctoresEspecialistas];
    }
    else {
        aux = new DoctorEspecialista[capDoctoresEspecialistas];
        for (int i = 0; i < numDoctoresEspecialistas; i++) {
            aux[i] = doctoresEspecialistas[i];
        }
        delete[] doctoresEspecialistas;
        doctoresEspecialistas = aux;
    }
}

void Clinica::incrementarCitasPresenciales() {
    CitaPresencial* aux;
    capCitasPresenciales += 5;

    if (citasPresenciales == nullptr) {
        citasPresenciales = new CitaPresencial[capCitasPresenciales];
    }
    else {
        aux = new CitaPresencial[capCitasPresenciales];
        for (int i = 0; i < numCitasPresenciales; i++) {
            aux[i] = citasPresenciales[i];
        }
        delete[] citasPresenciales;
        citasPresenciales = aux;
    }
}

void Clinica::incrementarCitasVirtuales() {
    CitaVirtual* aux;
    capCitasVirtuales += 5;

    if (citasVirtuales == nullptr) {
        citasVirtuales = new CitaVirtual[capCitasVirtuales];
    }
    else {
        aux = new CitaVirtual[capCitasVirtuales];
        for (int i = 0; i < numCitasVirtuales; i++) {
            aux[i] = citasVirtuales[i];
        }
        delete[] citasVirtuales;
        citasVirtuales = aux;
    }
}

int Clinica::getNumCitas() const {
    return numCitasPresenciales + numCitasVirtuales;
}

Clinica::~Clinica() {
    delete[] pacientesParticulares;
    delete[] pacientesAsegurados;
    delete[] doctoresGenerales;
    delete[] doctoresEspecialistas;
    delete[] citasPresenciales;
    delete[] citasVirtuales;
}

ofstream& operator<<(ofstream& os, const Clinica& clinica) {
    os << "CITAS PRESENCIALES" << endl;
    os << left
       << setw(8) << "FECHA" << " "
       << setw(4) << "HORA" << " "
       << setw(10) << "DNI_PAC" << " "
       << setw(20) << "NOMBRE_PAC"
       << setw(10) << "DNI_DOC" << " "
       << setw(20) << "NOMBRE_DOC"
       << setw(16) << "ESPECIALIDAD"
       << setw(12) << "ESTADO"
       << setw(20) << "CONSULTORIO"
       << "SEDE" << endl;

    for (int i = 0; i < clinica.numCitasPresenciales; i++) {
        os << clinica.citasPresenciales[i] << endl;
    }

    os << endl;
    os << "CITAS VIRTUALES" << endl;
    os << left
       << setw(8) << "FECHA" << " "
       << setw(4) << "HORA" << " "
       << setw(10) << "DNI_PAC" << " "
       << setw(20) << "NOMBRE_PAC"
       << setw(10) << "DNI_DOC" << " "
       << setw(20) << "NOMBRE_DOC"
       << setw(16) << "ESPECIALIDAD"
       << setw(12) << "ESTADO"
       << setw(18) << "PLATAFORMA"
       << "ENLACE" << endl;

    for (int i = 0; i < clinica.numCitasVirtuales; i++) {
        os << clinica.citasVirtuales[i] << endl;
    }

    return os;
}