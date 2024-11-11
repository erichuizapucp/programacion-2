/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on November 11, 2024, 9:57 AM
 */

#include <cstdlib>
#include "Universidad.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Universidad universidad;
    universidad.cargarAlumnos("alumnos.csv");
    universidad.imprimirAlumnos("reporte.txt");
    
    return 0;
}

