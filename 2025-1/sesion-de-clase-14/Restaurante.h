/* 
 * File:   Restaurante.h
 * Author: erichuiza
 *
 * Created on May 2, 2025, 5:21 PM
 */

#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "Mesero.h"

using namespace std;

class Restaurante {
private:
    Mesero** meseros;
    void incrementar(int&, int&);
public:
    Restaurante();
    Restaurante(const Restaurante&);
    
    void cargarMeseros(const char*);
    void mostrarMeseros();
    
    virtual ~Restaurante();
};

bool operator>>(ifstream&, Mesero&);
ostream& operator<<(ostream&, const Mesero&);
char* leerCadena(ifstream&, char=',');

#endif /* RESTAURANTE_H */

