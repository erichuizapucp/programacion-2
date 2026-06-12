//
// Created by Eric Huiza on 6/12/26.
//

#include "Alumno.h"

int Alumno::getCodigo() const {
    return codigo;
}

string Alumno::getNombre() const {
    return nombre;
}

int Alumno::getEdad() const {
    return edad;
}

int Alumno::getCiclo() const {
    return ciclo;
}

string Alumno::getFacultad() const {
    return facultad;
}

void Alumno::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Alumno::setNombre(string nombre) {
    this->nombre = nombre;
}

void Alumno::setEdad(int edad) {
    this->edad = edad;
}
void Alumno::setCiclo(int ciclo) {
    this->ciclo = ciclo;
}

void Alumno::setFacultad(string facultad) {
    this->facultad = facultad;
}

vector<Curso> Alumno::getCursos() const {
    return cursos;
}

void Alumno::setCursos(vector<Curso> cursos) {
    this->cursos = cursos;
}