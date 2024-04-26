/* 
 * File:   Persona.h
 * Author: erichuiza
 *
 * Created on April 22, 2024, 4:35 PM
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <cstring>

using namespace std;

class Persona {
private:
    double altura;
    double peso;
    const char* nacionalidad;
protected:
    int dni;
    int edad;
    const char* nombre;
public:
    Persona();
    Persona(const char*, int, int);
    Persona(const char*, int, int, double, double, const char*);
    
    void setNombre(const char*);
    void setDni(int);
    void setEdad(int);
    void setAltura(double);
    void setPeso(double);
    void setNacionalidad(const char*);
    
    void imprimir();
    
    ~Persona();
};

#endif /* PERSONA_H */

