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

using namespace std;

class Mesero {
private:
    int dni;
    char* nombre;
    double sueldo;
    int experiencia;
public:
    Mesero();
    Mesero(int, const char*, double, int);
    Mesero(const Mesero&);
    
    int getDni() const;
    void setDni(int);
    char* getNombre() const;
    void setNombre(const char*);
    double getSueldo() const;
    void setSueldo(double);
    int getExperiencia() const;
    void setExperiencia(int);
    
    Mesero& operator=(const Mesero&);
    bool operator>(const Mesero&);
    bool operator<(const Mesero&);
    
    virtual ~Mesero();
};

#endif /* MESERO_H */

