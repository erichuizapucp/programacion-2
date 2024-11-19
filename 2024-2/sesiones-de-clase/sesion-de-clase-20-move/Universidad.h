/* 
 * File:   Universidad.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 3:19 PM
 */

#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include <vector>
#include <fstream>
#include <iostream>
#include "AlumnoUniversitario.h"
#include <utility>

using namespace std;

class Universidad {
private:
    vector<AlumnoUniversitario> alumnos;
    
    void cargarAlumnos(ifstream&);
    void imprimirAlumnos(ofstream&);
public:
    Universidad();
    Universidad(const Universidad& orig);
    virtual ~Universidad();
    
    void cargarAlumnos(const char*);
    void imprimirAlumnos(const char*);
};

#endif /* UNIVERSIDAD_H */

