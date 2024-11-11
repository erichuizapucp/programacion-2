/* 
 * File:   Universidad.cpp
 * Author: erichuiza
 * 
 * Created on November 11, 2024, 10:44 AM
 */

#include "Universidad.h"
#include <fstream>
#include <iostream>

Universidad::Universidad() {
    alumnos = {};
}

Universidad::Universidad(const Universidad& orig) {
}

void Universidad::cargarAlumnos(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        exit(1);
    }
    
    cargarAlumnos(archivo);
}

void Universidad::imprimirAlumnos(const char* nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        exit(1);
    }
    
    imprimirAlumnos(archivo);
}

void Universidad::cargarAlumnos(ifstream& archivo) {
    AlumnoUniversitario alumno;
    while (archivo >> alumno) alumnos.push_back(alumno);
}

void Universidad::imprimirAlumnos(ofstream& archivo) {
    for (vector<AlumnoUniversitario>::iterator it = alumnos.begin(); it != alumnos.end(); ++it) {
        archivo << *it;
    }
//    while (it != alumnos.end()) {
//        
//        it++;
//    }
}

Universidad::~Universidad() {
}

