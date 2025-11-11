//
// Created by Eric Huiza on 11/7/25.
//

#include "Universidad.h"

void Universidad::cargarAlumnos(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    AlumnoInfo alumno;
    while (archivo >> alumno) {
        alumnos.push_back(alumno);
    }
    sort(alumnos.begin(), alumnos.end());
}

void Universidad::reporteAlumnos(const string& nombreArchivo) const {
    ofstream archivo(nombreArchivo);
    auto it = alumnos.cbegin();
    while (it != alumnos.cend()) {
        archivo << *it;
        ++it;
    }
}