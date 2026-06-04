#ifndef LABESTANTES_FUNCIONES_H
#define LABESTANTES_FUNCIONES_H

#include <fstream>

using namespace std;

char* leerCadena(ifstream&, char = ',');
void saltarEspacios(ifstream&);
void consumirComa(ifstream&);
void consumirFinLinea(ifstream&);

#endif
