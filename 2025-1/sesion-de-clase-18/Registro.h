/* 
 * File:   Registro.h
 * Author: erichuiza
 *
 * Created on May 30, 2025, 5:42 PM
 */

#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <fstream>

using namespace std;

class Registro {
protected: 
    char* leerCadena(ifstream&, char=',');
    virtual bool cargarDatos(ifstream&) = 0;
    virtual void imprimir(ostream&) const = 0;
public:
    friend bool operator>>(ifstream&, Registro&);
    friend ostream& operator<<(ostream&, const Registro&);
};

#endif /* REGISTRO_H */

