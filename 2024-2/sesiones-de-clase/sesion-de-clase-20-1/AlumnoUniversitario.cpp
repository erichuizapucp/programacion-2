/* 
 * File:   AlumnoUniversitario.cpp
 * Author: erichuiza
 * 
 * Created on November 11, 2024, 3:19 PM
 */

#include "AlumnoUniversitario.h"
#include "AlumnoRegular.h"
#include "AlumnoIntercambio.h"

AlumnoUniversitario::AlumnoUniversitario() {
    alumnoPtr = {};
}

AlumnoUniversitario::AlumnoUniversitario(const AlumnoUniversitario& orig) {
    this->alumnoPtr = orig.alumnoPtr->clonar();
}

bool operator>>(ifstream& archivo, AlumnoUniversitario& alumno) {
    if (archivo.eof()) return false;
    
    char tipo;
    archivo >> tipo;
    archivo.ignore();
    
    switch (tipo) {
        case 'R':
            alumno.alumnoPtr = new AlumnoRegular;
            break;
        case 'I':
            alumno.alumnoPtr = new AlumnoIntercambio;
            break;
        default:
            alumno.alumnoPtr = new AlumnoRegular;
            break;
    }
    
    archivo >> *alumno.alumnoPtr;
    
    return true;
}

ofstream& operator<<(ofstream& archivo, const AlumnoUniversitario& alumno) {
    archivo << *alumno.alumnoPtr;
    return archivo;
}

AlumnoUniversitario::~AlumnoUniversitario() {
    delete alumnoPtr;
}

