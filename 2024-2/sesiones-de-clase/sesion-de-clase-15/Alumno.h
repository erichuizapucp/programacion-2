/* 
 * File:   Alumno.h
 * Author: erichuiza
 *
 * Created on October 11, 2024, 4:45 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include "Persona.h"


class Alumno : public Persona {
private:
    int codigo;
    int ciclo;
public:
    Alumno();
    Alumno(const Alumno& orig);
    ~Alumno();
};

#endif /* ALUMNO_H */

