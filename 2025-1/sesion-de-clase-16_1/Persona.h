/* 
 * File:   Persona.h
 * Author: erichuiza
 *
 * Created on May 26, 2025, 4:21 PM
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <cstring>
#include <iostream>

using namespace std;

class Persona {
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
protected:
    int dni;
    char* nombre;
    
    void imprimirProtegido();
};

#endif /* PERSONA_H */

