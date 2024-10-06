/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on October 4, 2024, 4:04 PM
 */

#include <cstdlib>
#include "Alumno.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Alumno a1; // declara e instancia
    a1.setDni(46458348);
    a1.setNombre("Andrea");
    
    Alumno* a2; // declarando
    a2 = new Alumno; // instanciando
    a2->setDni(8747488);
    a2->setNombre("Diana");
    
    Alumno a3(34698745, "Juan");
    
    Alumno a4(34697897);
    a4.setNombre("Alexis");
    
    Alumno a5("Pedro");
    a5.setDni(79984948);
    
    Alumno* a6 = new Alumno(12345678, "Federico");
    
//    a1.imprimir();
//    a2->imprimir();
//    a3.imprimir();
//    a4.imprimir();
//    a5.imprimir();
//    a6->imprimir();
    
    imprimirAlumno(a1);
    
    return 0;
}

