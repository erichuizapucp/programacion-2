/* 
 * File:   Universidad.cpp
 * Author: erichuiza
 * 
 * Created on November 11, 2024, 3:19 PM
 */

#include "Universidad.h"
#include <utility>

Universidad::Universidad() {
    alumnos = {};
}

Universidad::Universidad(const Universidad& orig) {
}

void Universidad::cargarAlumnos(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "El archivo de entrada no se pudo abrir." << endl;
        exit(1);
    }
    
    cargarAlumnos(archivo);
}

void Universidad::imprimirAlumnos(const char* nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "El archivo de salida no se pudo abrir." << endl;
        exit(1);
    }
    
    imprimirAlumnos(archivo);
}


void Universidad::cargarAlumnos(ifstream& archivo) {
    AlumnoUniversitario alumno;
    while (archivo >> alumno) alumnos.push_back(std::move(alumno));
}

void Universidad::imprimirAlumnos(ofstream& archivo) {
    for (vector<AlumnoUniversitario>::iterator it = alumnos.begin(); it != alumnos.end(); ++it) {
        archivo << *it;
    }
//    vector<AlumnoUniversitario>::iterator it = alumnos.begin();
//    while (it != alumnos.end()) {
//        archivo << *it;
//        it++;
//    }
}

Universidad::~Universidad() {
}

