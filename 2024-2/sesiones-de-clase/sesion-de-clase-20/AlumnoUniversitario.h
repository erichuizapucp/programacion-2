/* 
 * File:   AlumnoUniversitario.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 10:20 AM
 */

#ifndef ALUMNOUNIVERSITARIO_H
#define ALUMNOUNIVERSITARIO_H

#include "Alumno.h"

class AlumnoUniversitario {
private:
    Alumno* alumnoPtr;
public:
    AlumnoUniversitario();
    AlumnoUniversitario(const AlumnoUniversitario& orig);
    virtual ~AlumnoUniversitario();
    
    friend bool operator>>(ifstream&, AlumnoUniversitario&);
    friend ofstream& operator<<(ofstream&, const AlumnoUniversitario&);
};

#endif /* ALUMNOUNIVERSITARIO_H */

