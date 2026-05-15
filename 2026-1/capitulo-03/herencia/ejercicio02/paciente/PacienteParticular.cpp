//
// Created by Eric Huiza on 5/15/26.
//

#include "PacienteParticular.h"

PacienteParticular::PacienteParticular() : Paciente() {
}

PacienteParticular::PacienteParticular(const PacienteParticular& origin) : Paciente(origin) {
}

PacienteParticular& PacienteParticular::operator=(const PacienteParticular& origin) {
    if (this != &origin) {
        Paciente::operator=(origin);
    }
    return *this;
}

ifstream& PacienteParticular::leer(ifstream& archivo) {
    if (!Paciente::leer(archivo)) {
        return archivo;
    }

    char* descartado = leerCadena(archivo);
    delete[] descartado;
    descartado = leerCadena(archivo, '\n');
    delete[] descartado;

    return archivo;
}

ofstream& PacienteParticular::imprimir(ofstream& archivo) const {
    archivo << "Tipo Paciente: PARTICULAR" << endl;
    Paciente::imprimir(archivo);

    return archivo;
}

ifstream& operator>>(ifstream& archivo, PacienteParticular& paciente) {
    return paciente.leer(archivo);
}

ofstream& operator<<(ofstream& archivo, const PacienteParticular& paciente) {
    return paciente.imprimir(archivo);
}
