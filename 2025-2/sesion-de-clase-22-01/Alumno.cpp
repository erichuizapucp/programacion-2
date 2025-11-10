//
// Created by Eric Huiza on 11/7/25.
//

#include "Alumno.h"

istream& Alumno::leer(istream& archivo) {
    if (!(archivo >> codigo)) {
        archivo.setstate(ios_base::failbit);
        return archivo;
    }

    archivo.ignore();
    getline(archivo, nombre, ',');
    archivo >> edad;
    archivo.ignore();

    return archivo;
}

ostream& Alumno::imprimir(ostream& archivo) const {
    archivo << "Codigo: " << codigo << ", "
            << "Nombre: " << nombre << ", "
            << "Edad: " << edad << ", ";

    return archivo;
}