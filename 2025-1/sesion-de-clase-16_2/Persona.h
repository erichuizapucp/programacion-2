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

using namespace std;

class Persona {
private:
    int dni;
    char* nombre;
public:
    Persona();
    Persona(int, const char*);
    Persona(const Persona& orig);
    
    int getDni() const;
    void setDni(int);
    char* getNombre() const;
    void setNombre(const char*);
    
    Persona& operator=(const Persona&);
    
    void imprimir(ostream&) const;
    
    virtual ~Persona();
};

#endif /* PERSONA_H */

