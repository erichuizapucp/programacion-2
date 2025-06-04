/* 
 * File:   Cliente.cpp
 * Author: erichuiza
 * 
 * Created on May 30, 2025, 11:56 AM
 */

#include "Cliente.h"

Cliente::Cliente() : Persona() {
    this->correo = nullptr;
    this->telefono = nullptr;
}

Cliente::Cliente(
    int dni, 
    const char* nombre, 
    const char* telefono, 
    const char* correo
) : Persona(dni, nombre) {
    this->setTelefono(telefono);
    this->setCorreo(correo);
}

Cliente::Cliente(const Cliente& orig) : Persona(orig) {
    *this = orig;
}

char* Cliente::getCorreo() const {
    return correo;
}

void Cliente::setCorreo(const char* correo) {
    if (this->correo) {
        delete[] this->correo;
    }
    
    this->correo = new char[strlen(correo) + 1];
    strcpy(this->correo, correo);
}

char* Cliente::getTelefono() const {
    return telefono;
}

void Cliente::setTelefono(const char* telefono) {
    if (this->telefono) {
        delete[] this->telefono;
    }
    
    this->telefono = new char[strlen(telefono) + 1];
    strcpy(this->telefono, telefono);
}

Cliente& Cliente::operator=(const Cliente& cliente) {
    Persona::operator=(cliente);
    this->setTelefono(cliente.getTelefono());
    this->setCorreo(cliente.getCorreo());
    
    return *this;
}

bool Cliente::cargarDatos(ifstream& archivo) {
    if (Persona::cargarDatos(archivo)) {
        char* telefono = this->leerCadena(archivo);
        char* email = this->leerCadena(archivo, '\n');
        
        this->setTelefono(telefono);
        this->setCorreo(email);
        
        return true;
    }
    return false;
}

void Cliente::imprimir(ostream& os) const {
    Persona::imprimir(os);
    os 
        << setw(20) << this->telefono
        << setw(20) << this->correo
        << endl;
}

Cliente::~Cliente() {
    delete[] this->telefono;
    delete[] this->correo;
}
