/* 
 * File:   ControladorRRHH.h
 * Author: erichuiza
 *
 * Created on April 28, 2024, 9:54 PM
 */

#ifndef CONTROLADORRRHH_H
#define CONTROLADORRRHH_H

#include "Persona.h"
#include "Estudiante.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

class ControladorRRHH final {
private:
    vector<Estudiante> estudiantes;
    ifstream archivoEstudiantes;
    ofstream archivoSalida;
    
    void cargaDatos(vector<Estudiante>&);
public:
    ControladorRRHH();
    ControladorRRHH(
        const char* nombreArchivo, 
        const char* nombreArchivoEstudiantes
    );
    ControladorRRHH(const char* nombreArchivo, vector<Estudiante>&);
    
    void imprimir();
    void grabar();
    
    ~ControladorRRHH();
};

//bool operator>>(ifstream&, Estudiante&);
//ostream& operator<< (ostream&, Estudiante);

#endif /* CONTROLADORRRHH_H */

