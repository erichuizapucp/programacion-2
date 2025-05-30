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
public:
    virtual bool cargarDatos(ifstream&) = 0;
    virtual void imprimir(ostream&) const = 0;
};

#endif /* REGISTRO_H */

