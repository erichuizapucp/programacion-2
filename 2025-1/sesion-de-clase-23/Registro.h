/* 
 * File:   Registro.h
 * Author: erichuiza
 *
 * Created on June 23, 2025, 11:27 AM
 */

#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Registro {
protected: 
    virtual bool cargarDatos(ifstream&) = 0;
    virtual void imprimir(ostream&) const = 0;
public:
    friend bool operator>>(ifstream&, Registro&);
    friend ostream& operator<<(ostream&, const Registro&);
};

#endif /* REGISTRO_H */

