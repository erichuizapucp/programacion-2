//
// Created by Eric Huiza on 11/7/25.
//

#include "AlumnoRegular.h"

Alumno* Alumno::clonar() const {
    return new AlumnoRegular();
}

istream& AlumnoRegular::leer(istream& archivo) {
    if (!Alumno::leer(archivo)) {
        archivo.setstate(ios_base::failbit);
        return archivo;
    }

    getline(archivo, facultad, ',');
    archivo >> ciclo;
    archivo.ignore();

    return archivo;
}

ostream& AlumnoRegular::imprimir(ostream& archivo) const {
    Alumno::imprimir(archivo);
    archivo << "Facultad: " << facultad << ", "
            << "Ciclo: " << ciclo << endl;

    return archivo;
}