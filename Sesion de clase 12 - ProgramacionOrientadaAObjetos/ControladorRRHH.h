/* 
 * File:   ControladorRRHH.h
 * Author: erichuiza
 *
 * Created on April 28, 2024, 9:54 PM
 */

#ifndef CONTROLADORRRHH_H
#define CONTROLADORRRHH_H

#include "Persona.h"
#include "AsignaMemoria.h"

#include <fstream>
#include <iostream>

class ControladorRRHH final : public AsignaMemoria {
private:
    Persona** personas;
    ifstream archivoEstudiantes;
    ofstream archivoSalida;
    
    void cargaEstudiantes(Persona**&);
public:
    ControladorRRHH();
    ControladorRRHH(
        const char* nombreArchivo, 
        const char* nombreArchivoEstudiantes
    );
    ControladorRRHH(const char* nombreArchivo, Persona**&);
    
    void imprimir();
    void grabar();
    
    ~ControladorRRHH();
};

#endif /* CONTROLADORRRHH_H */

