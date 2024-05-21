/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on April 21, 2024, 10:16 AM
 */

#include <cstdlib>
#include "Persona.h"
#include "Estudiante.h"
#include "ControladorRRHH.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc <= 1) {
        cerr << "Número de parámetros incorrecto.";
        exit(1);
    }
    
    const char* nombreArchivo = argv[1];
    const char* nombreArchivoEstudiantes = argv[2];
    
    ControladorRRHH* controlador = new ControladorRRHH(
        nombreArchivo,
        nombreArchivoEstudiantes
    );
    controlador->imprimir();
    controlador->grabar();
    
    delete controlador;
    
    return 0;
}

