//
// Created by Eric Huiza on 11/7/25.
//

#include "AlumnoIntercambio.h"

unique_ptr<Alumno> AlumnoIntercambio::clonar() const {
    // return new AlumnoIntercambio(*this);
    return make_unique<AlumnoIntercambio>(*this);
}

istream& AlumnoIntercambio::leer(istream& archivo) {
    if (!Alumno::leer(archivo)) {
        archivo.setstate(ios_base::failbit);
        return archivo;
    }

    getline(archivo, pais, ',');
    archivo >> duracion;
    archivo.ignore();

    return archivo;
}

ostream& AlumnoIntercambio::imprimir(ostream& archivo) const {
    Alumno::imprimir(archivo);
    archivo << "País: " << pais << ", "
            << "Duración: " << duracion << endl;

    return archivo;
}