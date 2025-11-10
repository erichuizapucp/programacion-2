//
// Created by Eric Huiza on 11/7/25.
//

#include "Universidad.h"

void Universidad::cargarAlumnos(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    AlumnoInfo alumno;
    while (archivo >> alumno) {
        cout << "(" << alumnos.size() << ", "
            << alumnos.capacity() << ")"
            << endl;
        alumnos.push_back(alumno);
    }
}

void Universidad::reporteAlumnos(const string& nombreArchivo) const {
    ofstream archivo(nombreArchivo);
    auto it = alumnos.cbegin();
    while (it != alumnos.cend()) {
        archivo << *it;
        ++it;
    }
}