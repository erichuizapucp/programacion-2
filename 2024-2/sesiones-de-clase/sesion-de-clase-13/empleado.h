/* 
 * File:   estructuras.h
 * Author: erichuiza
 *
 * Created on September 2, 2024, 4:41 PM
 */

#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <fstream>

using namespace std;

class Empleado {
private:
    int dni;
    char* nombre;
    double sueldoBruto;
    int experiencia;
    
    
public:
    void cargar(const char*, Empleado*&, int&);
    void cargar(const char*, Empleado*&);
    
    int getDni();
    char* getNombre();
    double getSueldoBruto();
    int getExperiencia();
    
    void setDni(int dni);
    void setNombre(char* nombre);
    void setSueldoBruto(double sueldoBruto);
    void setExperiencia(int experiencia);
//    bool operator<=(const Empleado&, const Empleado&);
//    bool operator>=(const Empleado&, const Empleado&);
};

bool operator>>(ifstream&, Empleado&);
ostream& operator<<(ostream&,const Empleado*);
char* leerCadena(ifstream&, char=',');

#endif /* EMPLEADO_H */

