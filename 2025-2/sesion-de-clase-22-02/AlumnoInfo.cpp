//
// Created by Eric Huiza on 11/7/25.
//

#include "AlumnoInfo.h"

#include "AlumnoIntercambio.h"
#include "AlumnoRegular.h"

AlumnoInfo::AlumnoInfo(const AlumnoInfo& origen) {
    *this = origen;
}

bool AlumnoInfo::operator<(const AlumnoInfo& origen) const {
    return this->alumnoPtr->nombre < origen.alumnoPtr->nombre;
}

AlumnoInfo& AlumnoInfo::operator=(const AlumnoInfo& origen) {
    if (this == &origen) {
        return *this;
    }
    this->alumnoPtr = origen.alumnoPtr->clonar();
    return *this;
}

istream& operator>>(istream& archivo, AlumnoInfo& alumno) {
    int tipoAlumno;
    if (!(archivo >> tipoAlumno)) {
        archivo.setstate(std::ios::failbit);
        return archivo;
    }
    archivo.ignore();
    switch (tipoAlumno) {
        case 0:
            alumno.alumnoPtr = make_unique<AlumnoRegular>();
            break;
        case 1:
            alumno.alumnoPtr = make_unique<AlumnoIntercambio>();
            break;
        default:
            alumno.alumnoPtr = make_unique<AlumnoRegular>();
            break;
    }

    archivo >> *alumno.alumnoPtr;
    return archivo;
}

ostream& operator<<(ostream& archivo, const AlumnoInfo& alumno) {
    archivo << *alumno.alumnoPtr;
    return archivo;
}
