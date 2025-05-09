/* 
 * File:   Persona.h
 * Author: erichuiza
 *
 * Created on April 28, 2025, 5:38 PM
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

using namespace std;

class Persona {
private:
    int dni;
    char* nombre;
    char* apellido;
    int edad;
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    
    void hablar();
    void escuchar();
    void correr();
    void dormir();
};

#endif /* PERSONA_H */

