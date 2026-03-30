//
// Created by Eric Huiza on 3/26/26.
//
//
// Created by Eric Huiza on 3/26/26.
//

#include "funciones.h"

void cargarPacientes(Clinica& clinica) {
    Paciente p1 { 11111111, 30, 'M' };
    Paciente p2 { 22222222, 25, 'F' };
    Paciente p3 { 33333333, 40, 'M' };
    Paciente p4 { 44444444, 35, 'F' };
    Paciente p5 { 55555555, 28, 'M' };

    clinica += p1;
    clinica += p2;
    clinica += p3;
    clinica += p4;
    clinica += p5;
}

void cargarDoctores(Clinica& clinica) {
    Doctor d1 { 12345678, NEUROLOGIA };
    Doctor d2 { 87645987, CARDIOLOGIA };
    Doctor d3 { 56781234, DERMATOLOGIA };
    Doctor d4 { 34567890, PSIQUIATRIA };

    clinica += d1;
    clinica += d2;
    clinica += d3;
    clinica += d4;
}

void cargarCitas(Clinica& clinica) {
    Paciente p1 = clinica.pacientes[0];
    Paciente p2 = clinica.pacientes[3];

    Doctor d1 = clinica.doctores[0];
    Doctor d2 = clinica.doctores[3];

    Cita cita1 { 20260328, 1530, p1, d1, RESERVADA };
    Cita cita2 { 20260329, 1030, p2, d2, RESERVADA };

    clinica += cita2;
    clinica += cita1;
}

Clinica& operator+=(Clinica& clinica, Paciente& paciente) {
    clinica.pacientes[clinica.numPacientes++] = paciente;
    return clinica;
}

Clinica& operator+=(Clinica& clinica, Doctor& doctor) {
    clinica.doctores[clinica.numDoctors++] = doctor;
    return clinica;
}

Clinica& operator+=(Clinica& clinica, Cita& cita) {
    insertarOrdenado(clinica, cita);
    return clinica;
}

bool operator<(Cita& cita1, Cita& cita2) {
    if (cita1.fecha == cita2.fecha) {
        return cita1.hora < cita2.hora;
    }
    return cita1.fecha < cita2.fecha;
}

Cita& operator!(Cita& cita) {
    cita.estado = CANCELADA;
    return cita;
}

ostream& operator<<(ostream& os, Paciente& paciente) {
    os << "DNI: " << paciente.dni << endl;
    os << "Edad: " << paciente.edad << endl;
    os << "Genero: " << paciente.genero << endl;

    return os;
}

ostream& operator<<(ostream& os, Doctor& doctor) {
    os << "DNI: " << doctor.dni << endl;
    imprimirEspecialidad(os, doctor.especialidad);

    return os;
}

ostream& operator<<(ostream& os, Cita& cita) {
    os << "DATOS DEL PACIENTE" << endl;
    os << "------------------" << endl;
    os << cita.paciente << endl;
    os << "DATOS DEL DOCTOR" << endl;
    os << "------------------" << endl;
    os << cita.doctor << endl;
    os << "DATOS DEL CITA" << endl;
    os << "------------------" << endl;
    imprimirFecha(os, cita.fecha);
    imprimirHora(os, cita.hora);
    imprimirEstado(os, cita.estado);

    return os;
}

ostream& operator<<(ostream& os, Clinica& clinica) {
    for (int i = 0; i < clinica.numCitas; i++) {
        cout << clinica.citas[i] << endl;
    }

    return os;
}

void insertarOrdenado(Clinica& clinica, Cita& nuevaCita) {
    int pos = 0;
    while (pos < clinica.numCitas && !(nuevaCita < clinica.citas[pos])) {
        pos++;
    }

    for (int i = clinica.numCitas; i > pos; i--) {
        clinica.citas[i] = clinica.citas[i - 1];
    }

    clinica.citas[pos] = nuevaCita;
    clinica.numCitas++;
}


void imprimirFecha(ostream& os, int fecha) {
    int anho = fecha / 10000;
    int mes = (fecha / 100) % 100;
    int dia = fecha % 100;

    os << "Fecha: " << anho << "-";
    if (mes < 10) os << "0";
    os << mes << "-";
    if (dia < 10) os << "0";
    os << dia << endl;
}

void imprimirHora(ostream& os, int hora) {
    int horas = hora / 100;
    int minutos = hora % 100;

    os << "Hora: ";
    if (horas < 10) os << "0";
    os << horas << ":";
    if (minutos < 10) os << "0";
    os << minutos << endl;
}

void imprimirEstado(ostream& os, Estado estado) {
    switch (estado) {
        case RESERVADA:
            os << "Estado: " << "RESERVADA" << endl;
            break;
        case CANCELADA:
            os << "Estado: " << "CANCELADA" << endl;
            break;
        default:
            os << "Estado: " << "NA" << endl;
            break;;
    }
}

void imprimirEspecialidad(ostream& os, Especialidad especialidad) {
    switch (especialidad) {
        case CARDIOLOGIA:
            os << "Especialidad: " << "CARDIOLOGÍA" << endl;
            break;
        case DERMATOLOGIA:
            os << "Especialidad: " << "DERMATOLOGÍA" << endl;
            break;
        case NEUROLOGIA:
            os << "Especialidad: " << "NEUROLOGÍA" << endl;
            break;
        case PEDIATRIA:
            os << "Especialidad: " << "PEDIATRÍA" << endl;
            break;
        case PSIQUIATRIA:
            os << "Especialidad: " << "PSIQUIATRÍA" << endl;
            break;
        default:
            os << "Especialidad: " << "NA" << endl;
            break;
    }
}
