/* 
 * File:   Persona.h
 * Author: erichuiza
 *
 * Created on October 11, 2024, 4:45 PM
 */

#ifndef PERSONA_H
#define PERSONA_H

class Persona {
private:
    int dni;
    char* nombre;
    int edad;
public:
    Persona();
    Persona(const Persona& orig);
    ~Persona();
};

#endif /* PERSONA_H */
