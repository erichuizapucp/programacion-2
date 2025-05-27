/* 
 * File:   Alumno.h
 * Author: erichuiza
 *
 * Created on May 26, 2025, 4:21 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include "Persona.h"

class Alumno : public Persona{
protected:
    void imprimirProtegido();
public:
    Alumno();
    Alumno(const Alumno& orig);
    
    void imprimir();
    
    virtual ~Alumno();
private:
    double promedio;
};

#endif /* ALUMNO_H */

