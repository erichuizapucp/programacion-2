//
// Created by Eric Huiza on 3/26/26.
//
//
// Created by Eric Huiza on 3/26/26.
//

#include "funciones.h"
#include <cstring>

void cargarPacientes(const char* nombreArchivo, Paciente*& pacientes) {
    int num = 0, capacidad = 0;
    pacientes = nullptr;
    Paciente paciente; // dato o fila en el archivo

    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> paciente) {
        if (num == capacidad) {
            incrementarPacientes(pacientes, num, capacidad);
        }
        pacientes[num] = paciente;
        num++;
    }
    pacientes[num] = { -1 };
}

void incrementarPacientes(Paciente*& pacientes, int num, int& capacidad) {
    Paciente* aux;
    capacidad += 5;

    if (pacientes == nullptr) { // primer incremento
        pacientes = new Paciente[capacidad + 1];
    }
    else {
        aux = new Paciente[capacidad + 1];
        for (int i = 0; i < num; i++) {
            aux[i] = pacientes[i];
        }
        delete pacientes;
        pacientes = aux;
    }
}

void cargarDoctores(const char* nombreArchivo, Doctor*& doctores) {
    int num = 0, capacidad = 0;
    doctores = nullptr;
    Doctor doctor;

    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> doctor) {
        if (num == capacidad) {
            incrementarDoctores(doctores, num, capacidad);
        }
        doctores[num] = doctor;
        num++;
    }

    doctores[num] = { -1 };
}

void incrementarDoctores(Doctor*& doctores, int num, int& capacidad) {
    Doctor* aux;
    capacidad += 5;
    if (doctores == nullptr) {
        doctores = new Doctor[capacidad + 1];
    }
    else {
        aux = new Doctor[capacidad + 1];
        for (int i = 0; i < num; i++) {
            aux[i] = doctores[i];
        }
        delete doctores;
        doctores = aux;
    }
}

void cargarCitas(const char* nombreArchivo, Cita*& citas) {
    int num = 0, capacidad = 0;
    citas = nullptr;
    Cita cita; // dato, fila

    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> cita) { // lee una fila en el archivo
        if (num == capacidad) {
            incrementarCitas(citas, num, capacidad);
        }
        citas[num] = cita;
        num++;
    }
    citas[num] = { -1 };
}

void incrementarCitas(Cita*& citas, int num, int& capacidad) {
    Cita* aux;
    capacidad += 5;
    if (citas == nullptr) {
        citas = new Cita[capacidad + 1];
    }
    else {
        aux = new Cita[capacidad + 1];
        for (int i = 0; i < num; i++) {
            aux[i] = citas[i];
        }
        delete citas;
        citas = aux;
    }
}

bool operator>>(ifstream& archivo, Paciente& paciente) {
    if (archivo >> paciente.dni) {
        archivo.ignore();
        paciente.nombre = leerCadena(archivo);
        archivo >> paciente.edad;
        archivo.ignore();
        archivo >> paciente.genero;
        archivo.ignore();
        return true;
    }

    return false;
}

bool operator>>(ifstream& archivo, Doctor& doctor) {
    if (archivo >> doctor.dni) {
        archivo.ignore();
        doctor.nombre = leerCadena(archivo);
        char* especialidad = leerCadena(archivo, '\n');
        doctor.especialidad = convertirEspecialidad(especialidad);
        delete[] especialidad;
        return true;
    }

    return false;
}

bool operator>>(ifstream& archivo, Cita& cita) {
    int anho;
    if (archivo >> anho) {
        archivo.ignore();
        int mes, dia, hora, minuto;
        archivo >> mes;
        archivo.ignore();
        archivo >> dia;
        cita.fecha = anho * 10000 + mes * 100 + dia;

        archivo.ignore();
        archivo >> hora;
        archivo.ignore();
        archivo >> minuto;
        cita.hora = hora * 100 + minuto;

        archivo.ignore();
        archivo >> cita.dniPaciente;
        archivo.ignore();
        archivo >> cita.dniDoctor;
        archivo.ignore();

        char* estado = leerCadena(archivo, '\n');
        cita.estado = convertirEstado(estado);
        delete[] estado;

        return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Paciente& paciente) {
    os << "DNI: " << paciente.dni << endl;
    os << "Nombre: " << paciente.nombre << endl;
    os << "Edad: " << paciente.edad << endl;
    os << "Genero: " << paciente.genero << endl;

    return os;
}

char* leerCadena(ifstream& archivo, char delim) {
    char buffer[100];
    archivo.getline(buffer, 100, delim);

    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

Especialidad convertirEspecialidad(const char* especialidad) {
    if (strcmp(especialidad, "CARDIOLOGIA") == 0) return CARDIOLOGIA;
    if (strcmp(especialidad, "DERMATOLOGIA") == 0) return DERMATOLOGIA;
    if (strcmp(especialidad, "NEUROLOGIA") == 0) return NEUROLOGIA;
    if (strcmp(especialidad, "PEDIATRIA") == 0) return PEDIATRIA;
    if (strcmp(especialidad, "PSIQUIATRIA") == 0) return PSIQUIATRIA;
    if (strcmp(especialidad, "TRAUMATOLOGIA") == 0) return TRAUMATOLOGIA;
    if (strcmp(especialidad, "ENDOCRINOLOGIA") == 0) return ENDOCRINOLOGIA;
    if (strcmp(especialidad, "GINECOLOGIA") == 0) return GINECOLOGIA;
    if (strcmp(especialidad, "PSICOLOGIA") == 0) return PSICOLOGIA;
    if (strcmp(especialidad, "ORTOPEDIA") == 0) return ORTOPEDIA;

    return GENERAL;
}

Estado convertirEstado(const char* estado) {
    if (strcmp(estado, "RESERVADA") == 0) return RESERVADA;
    if (strcmp(estado, "CANCELADA") == 0) return CANCELADA;
    return RESERVADA;
}

bool operator<(const Cita& cita1, const Cita& cita2) {
    if (cita1.fecha == cita2.fecha) {
        return cita1.hora < cita2.hora;
    }
    return cita1.fecha < cita2.fecha;
}

Cita& operator!(Cita& cita) {
    cita.estado = CANCELADA;
    return cita;
}

void procesarCitas(Clinica& clinica) {
    Paciente* pacientes = clinica.pacientes;
    Doctor* doctores = clinica.doctores;
    Cita* citas = clinica.citas;

    for (int i = 0; citas[i].fecha != -1; i++) {
        citas[i].paciente = obtenerPacientePorDni(citas[i].dniPaciente, pacientes);
        citas[i].doctor = obtenerDoctorPorDni(citas[i].dniDoctor, doctores);
    }
}

ostream& operator<<(ostream& os, const Doctor& doctor) {
    os << "DNI: " << doctor.dni << endl;
    os << "Nombre: " << doctor.nombre << endl;
    imprimirEspecialidad(os, doctor.especialidad);

    return os;
}

ostream& operator<<(ostream& os, const Cita& cita) {
    os << "==============================" << endl;
    os << "DATOS DEL CITA" << endl;
    os << "------------------------------" << endl;
    imprimirFecha(os, cita.fecha);
    imprimirHora(os, cita.hora);
    imprimirEstado(os, cita.estado);
    os << endl;
    os << "------------------------------" << endl;
    os << "DATOS DEL PACIENTE" << endl;
    os << "------------------------------" << endl;
    os << *cita.paciente << endl;
    os << "------------------------------" << endl;
    os << "DATOS DEL DOCTOR" << endl;
    os << "------------------------------" << endl;
    os << *cita.doctor << endl;
    os << "------------------------------" << endl;
    os << "==============================" << endl;

    return os;
}

ostream& operator<<(ostream& os, const Clinica& clinica) {
    for (int i = 0; clinica.citas[i].fecha != -1; i++) {
        os << clinica.citas[i] << endl;
    }

    return os;
}

void insertarOrdenado(Cita* citas, int& numCitas, const Cita& nuevaCita) {
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

const Paciente* obtenerPacientePorDni(int dni, const Paciente* pacientes) {
    for (int i = 0; pacientes[i].dni != -1; i++) {
        if (pacientes[i].dni == dni) {
            return &pacientes[i];
        }
    }
    return nullptr;
}

const Doctor* obtenerDoctorPorDni(int dni, const Doctor* doctores) {
    for (int i = 0; doctores[i].dni != -1; i++) {
        if (doctores[i].dni == dni) {
            return &doctores[i];
        }
    }
    return nullptr;
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
