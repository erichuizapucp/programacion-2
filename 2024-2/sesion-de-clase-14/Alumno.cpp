#include "Alumno.h"

Alumno::Alumno() {
    cout << "Constructor por defecto." << endl;
}

Alumno::Alumno(int dni, const char* nombre) {
    this->dni = dni;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
    
    cout << "Constructor propiamente dicho 1" << endl;
}

Alumno::Alumno(int dni) {
    this->dni = dni;

    cout << "Constructor propiamente dicho 2" << endl;
}

Alumno::Alumno(const char* nombre) {
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
    
    cout << "Constructor propiamente dicho 3" << endl;
}

void Alumno::setDni(int dni) {
    this->dni = dni;
}

void Alumno::setNombre(const char* nombre) {
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Alumno::imprimir() {
    cout << "DNI: " << this->dni << ", " << "Nombre: " << this->nombre << endl;
}

Alumno::Alumno(const Alumno& a) {
    *this = a;
    cout << "Constructor copia" << endl;
}

void Alumno::operator=(const Alumno& a) {
    this->dni = a.dni;
    this->nombre = new char[strlen(a.nombre) + 1];
    strcpy(this->nombre, a.nombre);
}

void imprimirAlumno(Alumno a) {
    a.imprimir();
}