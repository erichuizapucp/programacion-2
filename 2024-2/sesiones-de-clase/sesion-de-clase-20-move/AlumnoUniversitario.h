/* 
 * File:   AlumnoUniversitario.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 3:19 PM
 */

#ifndef ALUMNOUNIVERSITARIO_H
#define ALUMNOUNIVERSITARIO_H

#include <fstream>

#include "Alumno.h"

using namespace std;

class AlumnoUniversitario {
private:
    Alumno* alumnoPtr;
public:
    AlumnoUniversitario();
    AlumnoUniversitario(const AlumnoUniversitario&);
    AlumnoUniversitario(AlumnoUniversitario&&);
    virtual ~AlumnoUniversitario();
    
    AlumnoUniversitario& operator=(const AlumnoUniversitario&);
    AlumnoUniversitario& operator=(AlumnoUniversitario&&);
    
    friend bool operator>>(ifstream&, AlumnoUniversitario&);
    friend ofstream& operator<<(ofstream&, const AlumnoUniversitario&);
};

#endif /* ALUMNOUNIVERSITARIO_H */

