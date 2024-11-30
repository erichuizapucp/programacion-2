/* 
 * File:   AlumnoUniversitario.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 10:20 AM
 */

#ifndef ALUMNOUNIVERSITARIO_H
#define ALUMNOUNIVERSITARIO_H

#include <memory>

#include "Alumno.h"

using namespace std;

class AlumnoUniversitario {
private:
    Alumno* alumnoPtr; // Raw Pointer
public:
    AlumnoUniversitario();
    AlumnoUniversitario(const AlumnoUniversitario& orig);
    virtual ~AlumnoUniversitario();
    
    int getCodigo() const;
    char getTipo() const;
    string getNombre() const;
    string getApellido() const;
    // Sobrecarga del operador less - Inmutable
    bool operator<(const AlumnoUniversitario&) const;
    // Sobrecarga del operador greather - Inmutable
    bool operator>(const AlumnoUniversitario&) const;
    // Sobrecarga del operador de asignación de copia - Mutable
    AlumnoUniversitario& operator=(const AlumnoUniversitario&);
    
    friend ifstream& operator>>(ifstream&, AlumnoUniversitario&);
    friend ofstream& operator<<(ofstream&, const AlumnoUniversitario&);
};

#endif /* ALUMNOUNIVERSITARIO_H */

