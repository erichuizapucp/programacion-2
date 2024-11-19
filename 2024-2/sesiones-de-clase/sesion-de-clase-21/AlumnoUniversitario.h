/* 
 * File:   AlumnoUniversitario.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 10:20 AM
 */

#ifndef ALUMNOUNIVERSITARIO_H
#define ALUMNOUNIVERSITARIO_H

#include "Alumno.h"

using namespace std;

class AlumnoUniversitario {
private:
    Alumno* alumnoPtr;
public:
    AlumnoUniversitario();
    AlumnoUniversitario(const AlumnoUniversitario& orig);
    virtual ~AlumnoUniversitario();
    
    int getCodigo() const;
    char getTipo() const;
    string getNombre() const;
    string getApellido() const;
    bool operator<(const AlumnoUniversitario&) const;
    bool operator>(const AlumnoUniversitario&) const;
    AlumnoUniversitario& operator=(const AlumnoUniversitario&);
    
    friend ifstream& operator>>(ifstream&, AlumnoUniversitario&);
    friend ofstream& operator<<(ofstream&, const AlumnoUniversitario&);
};

#endif /* ALUMNOUNIVERSITARIO_H */

