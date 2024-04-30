/* 
 * File:   Persona.h
 * Author: erichuiza
 *
 * Created on April 29, 2024, 3:19 PM
 */

#ifndef PERSONA_H
#define PERSONA_H

class Persona {
private:
    int dni;
    char* nombre;
    int edad;
    double altura;
public:
    void imprimir();
};

#endif /* PERSONA_H */

