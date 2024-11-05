/* 
 * File:   Registro.h
 * Author: erichuiza
 *
 * Created on November 3, 2024, 2:03 PM
 */

#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "Enums.h"

using namespace std;

class Registro {
protected:
    virtual bool crear(ifstream&) = 0;
    virtual void imprimir(ofstream&) const = 0;
    static void copiarCadena(char*&, const char*);
    static char* leeCadena(ifstream&, char=',');
public:
    friend bool operator>>(ifstream&, Registro&);
};

#endif /* REGISTRO_H */