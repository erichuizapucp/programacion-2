/* 
 * File:   Cliente.cpp
 * Author: erichuiza
 * 
 * Created on May 30, 2025, 11:56 AM
 */

#include "Cliente.h"


Cliente::Cliente(
    int dni, 
    const string nombre, 
    const string telefono, 
    const string correo
) : Persona(dni, nombre) {
    this->setTelefono(telefono);
    this->setCorreo(correo);
}

string Cliente::getCorreo() const {
    return correo;
}

void Cliente::setCorreo(const string correo) {
    this->correo = correo;
}

string Cliente::getTelefono() const {
    return telefono;
}

void Cliente::setTelefono(const string telefono) {
    this->telefono = telefono;
}

bool Cliente::cargarDatos(ifstream& archivo) {
    if (Persona::cargarDatos(archivo)) {
        getline(archivo, telefono, ',');
        getline(archivo, correo, '\n');
        
        this->setTelefono(telefono);
        this->setCorreo(correo);
        
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
