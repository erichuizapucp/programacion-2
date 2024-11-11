/* 
 * File:   Universidad.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 10:44 AM
 */

#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include <vector>
#include "AlumnoUniversitario.h"

using namespace std;

class Universidad {
private:
    vector<AlumnoUniversitario> alumnos;
    
    void cargarAlumnos(ifstream&);
    void imprimirAlumnos(ofstream&);
public:
    Universidad();
    Universidad(const Universidad& orig);
    
    void cargarAlumnos(const char*);
    void imprimirAlumnos(const char*);
    
    virtual ~Universidad();
};

#endif /* UNIVERSIDAD_H */

