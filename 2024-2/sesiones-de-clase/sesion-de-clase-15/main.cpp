/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on October 11, 2024, 4:44 PM
 */

#include <cstdlib>

#include "AlumnoExtranjero.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Persona() -> Alumno() -> AlumnoExtranjero()
    // Por que los constructores se ejecutan de adentro a afuera.
    AlumnoExtranjero alumno1;
    
    // Los destructores de afuera a adentro.
    
    return 0;
}

