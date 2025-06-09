/* 
 * File:   Persona.h
 * Author: erichuiza
 *
 * Created on May 26, 2025, 4:29 PM
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

#include "Registro.h"

using namespace std;

class Persona : public Registro {
private:
    int dni;
    string nombre;
protected:
    virtual bool cargarDatos(ifstream&);
    virtual void imprimir(ostream&) const;
public:
    Persona() = default;
    Persona(int, string);
//    Persona(const Persona& orig);
    
    int getDni() const;
    void setDni(int);
    string getNombre() const;
    void setNombre(string);
    
//    virtual Persona& operator=(const Persona&);
    
    virtual ~Persona() = default;
};



#endif /* PERSONA_H */