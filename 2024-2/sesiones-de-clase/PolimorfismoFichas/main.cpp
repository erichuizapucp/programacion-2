/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on May 30, 2024, 9:21 PM
 */

#include <cstdlib>
#include "MovimientosEnTablero.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    MovimientosEnTablero movEnTabl;
    movEnTabl.cagar_y_moverfichas("Fichas.txt", "Movimientos.txt", "Reporte.txt");
    
    return 0;
}

