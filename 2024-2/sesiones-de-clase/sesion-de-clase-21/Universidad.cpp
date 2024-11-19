/* 
 * File:   Universidad.cpp
 * Author: erichuiza
 * 
 * Created on November 11, 2024, 10:44 AM
 */

#include "Universidad.h"

Universidad::Universidad() {
    alumnos = {};
}

Universidad::Universidad(const Universidad& orig) {
}

void Universidad::cargarAlumnos(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        exit(1);
    }
    
    cargarAlumnos(archivo);
}

void Universidad::imprimirAlumnos(const char* nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        exit(1);
    }
    
    imprimirAlumnos(archivo);
}

void Universidad::cargarAlumnos(ifstream& archivo) {
    AlumnoUniversitario alumno;
    while (archivo >> alumno) alumnos.push_back(alumno);
    sort(alumnos.begin(), alumnos.end(), OrdenaAlumnoPorNombre());
}

void Universidad::imprimirAlumnos(ofstream& archivo) {
    for (vector<AlumnoUniversitario>::iterator it = alumnos.begin(); it != alumnos.end(); ++it) {
        archivo << *it;
    }
}

void Universidad::cargarCursos(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        exit(1);
    }
    
    cargarCursos(archivo);
}

void Universidad::cargarCursos(ifstream& archivo) {
    Curso curso;
    while (archivo >> curso) cursos.push_back(curso);
}

void Universidad::imprimirCursos(const char* nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        exit(1);
    }
    
    imprimirCursos(archivo);
}

void Universidad::imprimirCursos(ofstream& archivo) {
    for (auto it = cursos.begin(); it != cursos.end(); ++it) {
        archivo << *it;
    }
}

void Universidad::matricular(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        exit(1);
    }
    
    matricular(archivo);
}

MapaInscripciones Universidad::cargarInscripciones(ifstream& archivo) {
    MapaInscripciones inscripciones;
    
    while (archivo) {
        int codigoCurso, codigoAlumno;
        archivo >> codigoCurso;
        archivo.ignore();
        archivo >> codigoAlumno;
        archivo.ignore();
        
        Curso curso = *find_if(cursos.begin(), cursos.end(), 
                [codigoCurso](const Curso& curso) {
            return curso.getCodigo() == codigoCurso;
        });
        
        if (inscripciones.find(curso) == inscripciones.end()) {
            InscripcionesCurso inscripcionAlumno;
            inscripciones[curso] = inscripcionAlumno;
        }
        
        AlumnoUniversitario alumno = *find_if(alumnos.begin(), alumnos.end(), 
                [codigoAlumno](const AlumnoUniversitario& alumno) {
            return alumno.getCodigo() == codigoAlumno;
        });
        
        inscripciones[curso].push(alumno);
    }
    
    return inscripciones;
}

void Universidad::matricular(ifstream& archivo) {
    MapaInscripciones inscripciones = cargarInscripciones(archivo);
    
    for (auto it = cursos.begin(); it != cursos.end(); ++it) {
        Curso curso = *it;
        InscripcionesCurso inscripcionesPorCurso = 
                inscripciones[curso];
        
        int capacidadDelCurso = curso.getCapacidad();
        list<AlumnoUniversitario> listaMatriculados;
        
        while (listaMatriculados.size() < capacidadDelCurso) {
            AlumnoUniversitario al = inscripcionesPorCurso.top();
            char tipo = al.getTipo();
            
            if (tipo == 'I') {
                listaMatriculados.push_front(inscripcionesPorCurso.top());
            }
            else {
                listaMatriculados.push_back(inscripcionesPorCurso.top());
            }
            inscripcionesPorCurso.pop();
        }
        matricula[curso] = listaMatriculados;
    }
}

void Universidad::imprimirMatricula(const char* nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        exit(1);
    }
    
    imprimirMatricula(archivo);
}

void Universidad::imprimirMatricula(ofstream& archivo) {
    for (vector<Curso>::iterator it = cursos.begin(); it != cursos.end(); ++it) {
        Curso curso = *it;
        
        archivo << "============================================================" << endl;
        archivo << "Código del Curso: " << curso.getCodigo() << endl;
        archivo << "Nombre del Curso: " << curso.getNombre() << endl;
        archivo << "Lista de matriculados: " << endl;
        
        list<AlumnoUniversitario> listaMatriculados = 
                matricula[curso];
        
        for (list<AlumnoUniversitario>::iterator itMat = listaMatriculados.begin(); itMat != listaMatriculados.end(); ++itMat) {
            AlumnoUniversitario alumno = *itMat;
            archivo << "Código del Alumno: " << alumno.getCodigo() << ", Nombre del Alumno: " << alumno.getNombre() << " " << alumno.getApellido() << endl;
        }
        archivo << "============================================================" << endl;
    }
}

Universidad::~Universidad() {
}

