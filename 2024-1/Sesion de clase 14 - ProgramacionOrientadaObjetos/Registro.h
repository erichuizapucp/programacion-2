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
    void cargar(ifstream&);
    void imprimir(ostream& = cout);
    void grabar(ofstream &);
};

#endif /* REGISTRO_H */
