/* 
 * File:   Alumno.h
 * Author: erichuiza
 *
 * Created on October 4, 2024, 4:04 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <cstring>

using namespace std;

class Alumno {
private:
    int dni;
    char* nombre;
public:
    Alumno();
    Alumno(int dni, const char* nombre);
    Alumno(int dni);
    Alumno(const char* nombre);
    Alumno(const Alumno& a);
    
    void setDni(int dni);
    void setNombre(const char* nombre);
    
    void imprimir();
    
    void operator=(const Alumno& a);
};

void imprimirAlumno(Alumno a);

#endif /* ALUMNO_H */

