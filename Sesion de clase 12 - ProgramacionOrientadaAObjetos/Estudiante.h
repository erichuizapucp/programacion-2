/* 
 * File:   Estudiante.h
 * Author: erichuiza
 *
 * Created on April 26, 2024, 3:44 PM
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>

#include "Persona.h"

class Estudiante : public Persona {
private:
    int codigo;
    const char* carrera;
    int annosEstudio;
    char categoria;
    char** cursos;
public:
    Estudiante();
    Estudiante(int, int, const char*, const char*, int, char, int, char**);
    
    void setCodigo(int);
    void setCarrera(const char*);
    void setAnnosEstudio(int);
    void setCategoria(char);
    void setCursos(char**);
    
    void imprimir();
    
    ~Estudiante();
};

#endif /* ESTUDIANTE_H */

