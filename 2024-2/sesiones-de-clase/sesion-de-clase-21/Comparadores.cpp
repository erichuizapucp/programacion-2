#include "Comparadores.h"
#include "AlumnoUniversitario.h"

bool OrdenaAlumnoPorNombre::operator()(const AlumnoUniversitario& a, const AlumnoUniversitario& b) const {
    string nombreCompletoA = a.getNombre() + " " + a.getApellido();
    string nombreCompletoB = b.getNombre() + " " + b.getApellido();
    
    return nombreCompletoA < nombreCompletoB;
}

bool OrdenaAlumnoPorCodigo::operator()(const AlumnoUniversitario& a, const AlumnoUniversitario& b) const {
    return a.getCodigo() < b.getCodigo();
}
