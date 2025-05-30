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
    char* leerCadena(ifstream&, char=',');
public:
    Persona();
    Persona(int, const char*);
    Persona(const Persona& orig);
    
    int getDni() const;
    void setDni(int);
    char* getNombre() const;
    void setNombre(const char*);
    
    virtual Persona& operator=(const Persona&);
    
    // aún son públicos porque los operadores no son métodos friend
    virtual bool cargarDatos(ifstream&);
    virtual void imprimir(ostream&) const;
    
    virtual ~Persona();
};

bool operator>>(ifstream&, Persona&);
ostream& operator<<(ostream&, const Persona&);

#endif /* PERSONA_H */