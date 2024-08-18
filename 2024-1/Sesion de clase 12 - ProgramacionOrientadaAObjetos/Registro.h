/* 
 * File:   Registro.h
 * Author: erichuiza
 *
 * Created on April 28, 2024, 10:52 PM
 */

#ifndef REGISTRO_H
#define REGISTRO_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

class Registro {
protected:
    char* leerCadena(istream&, char = ',');
public:
    virtual void cargar(ifstream&) = 0;
    virtual void imprimir() = 0;
    virtual void grabar(ofstream &) = 0;
//    virtual void foo() = 0;
};

#endif /* REGISTRO_H */
