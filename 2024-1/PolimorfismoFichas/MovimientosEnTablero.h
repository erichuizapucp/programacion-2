/* 
 * File:   MovimientosEnTablero.h
 * Author: erichuiza
 *
 * Created on May 30, 2024, 11:09 PM
 */

#ifndef MOVIMIENTOSENTABLERO_H
#define MOVIMIENTOSENTABLERO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Tablero.h"

using namespace std;

class MovimientosEnTablero {
private:
    Tablero tablero;
public:
    void cagar_y_moverfichas(const char*, const char*, const char*);
};

#endif /* MOVIMIENTOSENTABLERO_H */

