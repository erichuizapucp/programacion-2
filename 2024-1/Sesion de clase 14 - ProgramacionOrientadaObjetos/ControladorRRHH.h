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
#include "Estudiante.h"

#include <fstream>
#include <iostream>

class ControladorRRHH final : public AsignaMemoria {
private:
    Estudiante** estudiantes;
    ifstream archivoEstudiantes;
    ofstream archivoSalida;
    
    void cargaDatos(Estudiante**&);
public:
    ControladorRRHH();
    ControladorRRHH(
        const char* nombreArchivo, 
        const char* nombreArchivoEstudiantes
    );
    ControladorRRHH(const char* nombreArchivo, Estudiante**&);
    
    void imprimir();
    void grabar();
    
    ~ControladorRRHH();
};

bool operator>>(ifstream&, Estudiante*&);
ostream& operator<< (ostream&, Estudiante*);

#endif /* CONTROLADORRRHH_H */

