//
// Created by Eric Huiza on 9/22/25.
//

#include "Usuario.h"

Usuario::Usuario() {
    cuenta = nullptr;
    nombre = nullptr;
    correo = nullptr;
    facultad = nullptr;
    edad = 0;
    fechaRegistro = 0;
}

Usuario& Usuario::operator=(const Usuario& usuario) {
    this->setCuenta(usuario.getCuenta());
    this->setNombre(usuario.getNombre());
    this->setCorreo(usuario.getCorreo());
    this->setFacultad(usuario.getFacultad());
    this->setEdad(usuario.getEdad());
    return *this;
}

char * Usuario::getCuenta() const {
    return cuenta;
}

void Usuario::setCuenta(const char* cuenta) {
    delete[] this->cuenta;
    if (cuenta) {
        this->cuenta = new char[strlen(cuenta) + 1];
        strcpy(this->cuenta, cuenta);
    }
    else {
        this->cuenta = nullptr;
    }
}

char * Usuario::getNombre() const {
    return nombre;
}

void Usuario::setNombre(const char* nombre) {
    delete[] this->nombre;
    if (nombre) {
        this->nombre = new char[strlen(nombre) + 1];
        strcpy(this->nombre, nombre);
    }
    else {
        this->nombre = nullptr;
    }
}

char * Usuario::getCorreo() const {
    return correo;
}

void Usuario::setCorreo(const char* correo) {
    delete[] this->correo;
    if (correo) {
        this->correo = new char[strlen(correo) + 1];
        strcpy(this->correo, correo);
    }
    else {
        this->correo = nullptr;
    }
}

char * Usuario::getFacultad() const {
    return facultad;
}

void Usuario::setFacultad(const char* facultad) {
    delete[] this->facultad;
    if (facultad) {
        this->facultad = new char[strlen(facultad) + 1];
        strcpy(this->facultad, facultad);
    }
    else {
        this->facultad = nullptr;
    }
}

int Usuario::getEdad() const {
    return edad;
}

void Usuario::setEdad(int edad) {
    this->edad = edad;
}

int Usuario::getFechaRegistro() const {
    return fechaRegistro;
}

void Usuario::setFechaRegistro(int fechaRegistro) {
    this->fechaRegistro = fechaRegistro;
}

char* Usuario::leerCadena(istream& is) {
    char buffer[100];
    is.getline(buffer, 100, ',');
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

Usuario::~Usuario() {
    delete[] cuenta;
    delete[] nombre;
    delete[] correo;
    delete[] facultad;
}

istream& operator>>(istream& is, Usuario& usuario) {
    char* cuenta = usuario.leerCadena(is);

    if (!is || cuenta[0] == '\n') {
        delete[] cuenta;
        return is;
    }
    usuario.setCuenta(cuenta);
    delete[] cuenta;

    char* nombre = usuario.leerCadena(is);
    usuario.setNombre(nombre);
    delete[] nombre;

    char* correo = usuario.leerCadena(is);
    usuario.setCorreo(correo);
    delete[] correo;

    char* facultad = usuario.leerCadena(is);
    usuario.setFacultad(facultad);
    delete[] facultad;

    int anho, mes, dia;
    is >> anho;
    is.ignore();
    is >> mes;
    is.ignore();
    is >> dia;
    is.ignore();
    int fecha = anho * 10000 + mes * 100 + dia;
    usuario.setFechaRegistro(fecha);

    int edad;
    is >> edad;
    usuario.setEdad(edad);
    is.ignore();

    return is;
}

ostream& operator<<(ostream& os, const Usuario& usuario) {
    os << "Cuenta: " << usuario.getCuenta() << endl;
    os << "Nombre: " << usuario.getNombre() << endl;
    os << "Correo: " << usuario.getCorreo() << endl;
    os << "Facultad: " << usuario.getFacultad() << endl;
    os << "Edad: " << usuario.getEdad() << endl;
    os << "Fecha de Registro: " << usuario.getFechaRegistro() << endl;
    return os;
}