/* 
 * File:   AlumnoUniversitario.cpp
 * Author: erichuiza
 * 
 * Created on November 11, 2024, 10:20 AM
 */

#include "AlumnoUniversitario.h"
#include "AlumnoRegular.h"
#include "AlumnoIntercambio.h"

AlumnoUniversitario::AlumnoUniversitario() {
    alumnoPtr = {};
}

AlumnoUniversitario::AlumnoUniversitario(const AlumnoUniversitario& orig) {
    *this = orig;
}

int AlumnoUniversitario::getCodigo() const {
    return this->alumnoPtr->getCodigo();
}

char AlumnoUniversitario::getTipo() const {
    return this->alumnoPtr->getTipo();
}

string AlumnoUniversitario::getNombre() const {
    return this->alumnoPtr->getNombre();
}

string AlumnoUniversitario::getApellido() const {
    return this->alumnoPtr->getApellido();
}

AlumnoUniversitario& AlumnoUniversitario::operator=(const AlumnoUniversitario& orig) {
    this->alumnoPtr = orig.alumnoPtr->clonar();
    return *this;
}

bool AlumnoUniversitario::operator<(const AlumnoUniversitario& alumno) const {
    return this->alumnoPtr->getPromedio() < alumno.alumnoPtr->getPromedio();
}

bool AlumnoUniversitario::operator>(const AlumnoUniversitario& alumno) const {
    return this->alumnoPtr->getPromedio() > alumno.alumnoPtr->getPromedio();
}

ifstream& operator>>(ifstream& archivo, AlumnoUniversitario& alumno) {
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
    
    return archivo;
}

ofstream& operator<<(ofstream& archivo, const AlumnoUniversitario& alumno) {
    archivo << *alumno.alumnoPtr;
    return archivo;
}

AlumnoUniversitario::~AlumnoUniversitario() {
    delete alumnoPtr;
}
