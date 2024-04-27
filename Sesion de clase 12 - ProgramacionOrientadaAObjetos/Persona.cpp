#include "Persona.h"

Persona::Persona() : dni(0), edad(0), altura(0.0), peso(0.0) {
    cout << "Constructor por defecto." << endl;
    
    this->nombre = nullptr;
    this->nacionalidad = nullptr;
}

Persona::Persona(const char* nombre, int dni, int edad) 
    : nombre(nombre), dni(dni), edad(edad) {
    cout << "Constructor sobrecargado de Persona #1" << endl;
}

Persona::Persona(
    const char* nombre, 
    int dni, 
    int edad, 
    double altura, 
    double peso, 
    const char* nacionalidad
) : dni(dni), 
    edad(edad), 
    altura(altura), 
    peso(peso), 
    nombre(nombre), 
    nacionalidad(nacionalidad)        
{
    cout << "Constructor sobrecargado de Persona #2." << endl;
//    this->nombre = new char[strlen(nombre) + 1];
//    strcpy(this->nombre, nombre);
//
//    this->nacionalidad = new char[strlen(nacionalidad) + 1];
//    strcpy(this->nacionalidad, nacionalidad);
}

void Persona::setNombre(const char* nombre) {
    this->nombre = nombre;
//    if (this->nombre != nullptr) {
//        delete[] this->nombre;
//    }
//    this->nombre = new char[strlen(nombre) + 1];
//    strcpy(this->nombre, nombre);
}

void Persona::setDni(int dni) {
    this->dni = dni;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::setAltura(double altura) {
    this->altura = altura;
}

void Persona::setPeso(double peso) {
    this->peso = peso;
}

void Persona::setNacionalidad(const char* nacionalidad) {
    this->nacionalidad = nacionalidad;
//    if (this->nacionalidad != nullptr) {
//        delete[] this->nacionalidad;
//    }
//    this->nacionalidad = new char[strlen(nacionalidad) + 1];
//    strcpy(this->nacionalidad, nacionalidad);
}

void Persona::imprimir() {
    if (nombre != nullptr) {
        cout << "Nombre: " << nombre << endl;
    }
    
    if (dni > 0) {
        cout << "DNI: " << dni << endl;
    }
    
    if (edad > 0) {
        cout << "Edad: " << edad << endl; 
    }
    
    if (altura > 0.0) {
        cout << "Altura: " << altura << endl;
    }
    
    if (peso > 0.0) {
        cout << "Peso: " << peso << endl;;
    }
    
    if (nacionalidad != nullptr) {
        cout << "Nacionalidad: " << nacionalidad << endl;
    }
}

Persona::~Persona() {
    cout << "Se destruye el objeto " << this << endl;;

//    if (nombre != nullptr) {
//        delete[] nombre;
//    }
//    
//    if (nacionalidad != nullptr) {
//        delete[] nacionalidad;
//    }
}