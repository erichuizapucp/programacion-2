/* 
 * File:   Mesero.h
 * Author: erichuiza
 *
 * Created on May 2, 2025, 5:22 PM
 */

#ifndef MESERO_H
#define MESERO_H

#include <cstring>
#include <iostream>
#include <fstream>

#include "Persona.h"

using namespace std;

class Mesero : public Persona {
private:
    double sueldo;
    int experiencia;
public:
    Mesero();
    Mesero(int, const char*, double, int);
    Mesero(const Mesero&);
    
    double getSueldo() const;
    void setSueldo(double);
    int getExperiencia() const;
    void setExperiencia(int);
    
    Mesero& operator=(const Mesero&);
    bool cargarDatos(ifstream&);
    void imprimir(ostream&) const;
    
    virtual ~Mesero();
};

#endif /* MESERO_H */

