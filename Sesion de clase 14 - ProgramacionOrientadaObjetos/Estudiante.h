/* 
 * File:   Estudiante.h
 * Author: erichuiza
 *
 * Created on April 26, 2024, 3:44 PM
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <iomanip>
#include <sstream>

#include "Persona.h"

class Estudiante : public Persona {
private:
    int codigo;
    char* carrera;
    int annosEstudio;
    char categoria;
    char** cursos;
    
    char** leerCursos(char*&);
    void imprimirCursos(ostream& = cout);
    void grabarCursos(ofstream&);
public:
    Estudiante();
    Estudiante(int, int, char*, int, double, double, Nacionalidad, 
               char*, int, char, char**);
    
    void setCodigo(int);
    void setCarrera(char*);
    void setAnnosEstudio(int);
    void setCategoria(char);
    void setCursos(char**);
    
    void cargar(ifstream&);
    void imprimir(ostream& = cout);
    void grabar(ofstream &);
    
    ~Estudiante();
};

#endif /* ESTUDIANTE_H */

