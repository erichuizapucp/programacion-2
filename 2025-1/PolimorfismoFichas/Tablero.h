/* 
 * File:   Tablero.h
 * Author: erichuiza
 *
 * Created on May 30, 2024, 10:50 PM
 */

#ifndef TABLERO_H
#define TABLERO_H

#include <fstream>
#include <iostream>
#include "Ficha.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include "Nodo.h"

using namespace std;

class Tablero {
private:
//    Ficha *ficha[100];
    Nodo* cabeza;
//    int numFichas;
public:
    Tablero();
    virtual ~Tablero();
    void leerFichas(ifstream&);
    void colocarFicha(char*, char, int, int);
    void leerMovimientos(ifstream&);
    void moverFicha(char*, char, int);
    void imprimeDatos(ofstream&);
};

#endif /* TABLERO_H */

