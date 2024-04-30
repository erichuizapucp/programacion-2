/* 
 * File:   Persona.h
 * Author: erichuiza
 *
 * Created on April 22, 2024, 4:35 PM
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <fstream>
#include <iostream>
#include <cstring>

#include "Enums.h"
#include "Registro.h"
#include "AsignaMemoria.h"

using namespace std;

class Persona : public Registro, public AsignaMemoria {
private:
    int dni;
    char* nombre;
    int edad;
    double altura;
    double peso;
    
    const char* nacionalidadACadena(Nacionalidad);
    Nacionalidad nacionalidadAEnum(char*);
protected:
    Nacionalidad nacionalidad;
public:
    Persona();
    Persona(int, char*, int, double, double, Nacionalidad);
    
    void setNombre(char*);
    void setDni(int);
    void setEdad(int);
    void setAltura(double);
    void setPeso(double);
    void setNacionalidad(const Nacionalidad);
    
    virtual void cargar(ifstream&);
    virtual void imprimir();
    virtual void grabar(ofstream&);
    
    virtual ~Persona();
};

#endif /* PERSONA_H */

