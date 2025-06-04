/* 
 * File:   Persona.h
 * Author: erichuiza
 *
 * Created on May 26, 2025, 4:29 PM
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Registro.h"

using namespace std;

class Persona : public Registro {
private:
    int dni;
    char* nombre;
protected:
    virtual bool cargarDatos(ifstream&);
    virtual void imprimir(ostream&) const;
public:
    Persona();
    Persona(int, const char*);
    Persona(const Persona& orig);
    
    int getDni() const;
    void setDni(int);
    char* getNombre() const;
    void setNombre(const char*);
    
    virtual Persona& operator=(const Persona&);
    
    virtual ~Persona();
};



#endif /* PERSONA_H */