//
// Created by Eric Huiza on 11/7/25.
//

#include "AlumnoRegular.h"

unique_ptr<Alumno> AlumnoRegular::clonar() const {
    // return new AlumnoRegular(*this);
    return make_unique<AlumnoRegular>(*this);
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