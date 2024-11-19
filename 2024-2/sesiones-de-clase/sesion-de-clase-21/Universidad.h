/* 
 * File:   Universidad.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 10:44 AM
 */

#ifndef UNIVERSIDAD_H
#define UNIVERSIDAD_H

#include <vector>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
#include "AlumnoUniversitario.h"
#include "Curso.h"
#include "Comparadores.h"

using namespace std;

using InscripcionesCurso = priority_queue<AlumnoUniversitario, vector<AlumnoUniversitario>, greater<AlumnoUniversitario>>;
using MapaInscripciones = map<Curso, InscripcionesCurso>;

class Universidad {
private:
    vector<AlumnoUniversitario> alumnos;
    vector<Curso> cursos;
    MapaInscripciones inscripciones;
    map<Curso, list<AlumnoUniversitario>> matricula;
    
    void cargarAlumnos(ifstream&);
    void imprimirAlumnos(ofstream&);
    
    void cargarCursos(ifstream&);
    void imprimirCursos(ofstream&);
    
    MapaInscripciones cargarInscripciones(ifstream&);
    void matricular(ifstream&);
    void imprimirMatricula(ofstream&);
public:
    Universidad();
    Universidad(const Universidad& orig);
    
    void cargarAlumnos(const char*);
    void imprimirAlumnos(const char*);
    
    void cargarCursos(const char*);
    void imprimirCursos(const char*);
    
    void matricular(const char*);
    void imprimirMatricula(const char*);
    
    virtual ~Universidad();
};

#endif /* UNIVERSIDAD_H */

