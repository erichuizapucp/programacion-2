//
// Created by Eric Huiza on 11/7/25.
//

#include "AlumnoInfo.h"

AlumnoInfo::AlumnoInfo(const AlumnoInfo& origen) {
    this->alumnoPtr = origen.alumnoPtr;
}

AlumnoInfo& AlumnoInfo::operator=(const AlumnoInfo& origen) {
    if (this != &origen) {
        return *this;
    }
    return new AlumnoInfo(origen.alumnoPtr->clonar());
}

istream& operator>>(istream& archivo, AlumnoInfo& alumno) {
    archivo >> *alumno.alumnoPtr;
    return archivo;
}

ostream& operator<<(ostream& archivo, const AlumnoInfo& alumno) {
    archivo << *alumno.alumnoPtr;
    return archivo;
}

AlumnoInfo::~AlumnoInfo() {
    delete alumnoPtr;
}