//
// Created by Eric Huiza on 3/26/26.
//
//
// Created by Eric Huiza on 3/26/26.
//

#include "funciones.h"
#include <cstring>

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
