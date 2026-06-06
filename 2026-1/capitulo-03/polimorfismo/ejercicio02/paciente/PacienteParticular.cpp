//
// Created by Eric Huiza on 5/15/26.
//

#include "PacienteParticular.h"

PacienteParticular::PacienteParticular() {
    categoria = 'N';
}

PacienteParticular::PacienteParticular(const PacienteParticular& origin) : PacienteParticular() {
    *this = origin;
}

char PacienteParticular::getCategoria() const {
    return categoria;
}

void PacienteParticular::setCategoria(char categoria) {
    this->categoria = categoria;
}

PacienteParticular& PacienteParticular::operator=(const PacienteParticular& origin) {
    if (this != &origin) {
        Paciente::operator=(origin);
        this->setCategoria(origin.getCategoria());
    }
    return *this;
}

ifstream& PacienteParticular::leer(ifstream& archivo) {
    if (!Paciente::leer(archivo)) {
        return archivo;
    }

    char categoria;
    archivo >> categoria;
    this->setCategoria(categoria);

    return archivo;
}

ofstream& PacienteParticular::imprimir(ofstream& archivo) const {
    archivo << "Tipo Paciente: PARTICULAR" << endl;
    Paciente::imprimir(archivo);
    archivo << "Categoria: " << this->getCategoria() << endl;

    return archivo;
}
