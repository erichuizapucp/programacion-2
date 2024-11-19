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
    universidad.imprimirAlumnos("alumnos.txt");
    
    universidad.cargarCursos("cursos.csv");
    universidad.imprimirCursos("cursos.txt");
    
    universidad.matricular("inscripciones.csv");
    universidad.imprimirMatricula("matricula.txt");
    
    return 0;
}

