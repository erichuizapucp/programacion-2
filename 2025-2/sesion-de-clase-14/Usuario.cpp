//
// Created by Eric Huiza on 9/26/25.
//

#include "Usuario.h"


Usuario::Usuario() {
    this->cuenta = nullptr;
    this->nombre = nullptr;
    this->correo = nullptr;
    this->facultad = nullptr;
    this->fechaRegistro = 0;
    this->edad = 0;
}

Usuario::Usuario(const Usuario& origen) : Usuario() {
    *this = origen;
}

Usuario::Usuario(char* cuenta,
                 char* nombre,
                 char* email,
                 char* facultad) : Usuario() {
    this->setCuenta(cuenta);
    this->setNombre(nombre);
    this->setCorreo(email);
    this->setFacultad(facultad);
}

Usuario::Usuario(int fechaRegistro, int edad) : Usuario() {
    this->fechaRegistro = fechaRegistro;
    this->edad = edad;
}

Usuario::Usuario(char* cuenta,
                 char* nombre,
                 char* email,
                 char* facultad,
                 int fechaRegistro,
                 int edad) : Usuario() {
    this->setCuenta(cuenta);
    this->setNombre(nombre);
    this->setCorreo(email);
    this->setFacultad(facultad);
    this->setFechaRegistro(fechaRegistro);
    this->setEdad(edad);
}

char* Usuario::getCuenta() const {
    return cuenta;
}

void Usuario::setCuenta(char* cuenta) {
    delete[] this->cuenta;
    if (cuenta) {
        this->cuenta = new char[strlen(cuenta) + 1];
        strcpy(this->cuenta, cuenta);
    }
    else {
        this->cuenta = nullptr;
    }
}

char* Usuario::getNombre() const {
    return nombre;
}

void Usuario::setNombre(char* nombre) {
    delete[] this->nombre;
    if (nombre) {
        this->nombre = new char[strlen(nombre) + 1];
        strcpy(this->nombre, nombre);
    }
    else {
        this->nombre = nullptr;
    }
}

char* Usuario::getCorreo() const {
    return correo;
}

void Usuario::setCorreo(char* correo) {
    delete[] this->correo;
    if (correo) {
        this->correo = new char[strlen(correo) + 1];
        strcpy(this->correo, correo);
    }
    else {
        this->correo = nullptr;
    }
}

char* Usuario::getFacultad() const {
    return facultad;
}

void Usuario::setFacultad(char* facultad) {
    delete[] this->facultad;
    if (facultad) {
        this->facultad = new char[strlen(facultad) + 1];
        strcpy(this->facultad, facultad);
    }
    else {
        this->facultad = nullptr;
    }
}

int Usuario::getFechaRegistro() const {
    return fechaRegistro;
}

void Usuario::setFechaRegistro(int fechaRegistro) {
    this->fechaRegistro = fechaRegistro;
}

int Usuario::getEdad() const {
    return edad;
}

void Usuario::setEdad(int edad) {
    this->edad = edad;
}

bool Usuario::operator==(const Usuario& usuario) const {
    return strcmp(getCuenta(), usuario.getCuenta()) == 0;
}

bool Usuario::operator<(const Usuario& usuario) const {
    return getEdad() < usuario.getEdad();
}

bool Usuario::operator>(const Usuario& usuario) const {
    return getEdad() > usuario.getEdad();
}

bool Usuario::operator<=(const Usuario& usuario) const {
    return getEdad() <= usuario.getEdad();
}

bool Usuario::operator>=(const Usuario& usuario) const {
    return getEdad() >= usuario.getEdad();
}

Usuario::operator int() const {
    return edad;
}

Usuario::operator char*() const {
    return nombre;
}

char* Usuario::leerCadena(istream& archivo, char delim) {
    char buffer[100];
    archivo.getline(buffer, 100, delim);
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

istream& operator>>(istream& archivo, Usuario& usuario) {
    char* cuenta = usuario.leerCadena(archivo);
    if (!archivo || cuenta[0] == '\0') {
        delete[] cuenta;
        return archivo;
    }

    char* nombre = usuario.leerCadena(archivo);
    char* correo = usuario.leerCadena(archivo);
    char* facultad = usuario.leerCadena(archivo);

    int anho, mes, dia;
    archivo >> anho;
    archivo.ignore();
    archivo >> mes;
    archivo.ignore();
    archivo >> dia;
    archivo.ignore();
    // 20250926
    int fechaRegistro = anho * 10000 + mes * 100 + dia;
    int edad;
    archivo >> edad;
    archivo.ignore();

    usuario.setCuenta(cuenta);
    usuario.setNombre(nombre);
    usuario.setCorreo(correo);
    usuario.setFacultad(facultad);
    usuario.setFechaRegistro(fechaRegistro);
    usuario.setEdad(edad);

    delete[] cuenta;
    delete[] nombre;
    delete[] facultad;
    delete[] correo;

    return archivo;
}

Usuario& Usuario::operator=(const Usuario& usuario) {
    if (this == &usuario) {
        return *this;
    }

    this->setCuenta(usuario.getCuenta());
    this->setNombre(usuario.getNombre());
    this->setCorreo(usuario.getCorreo());
    this->setFacultad(usuario.getFacultad());
    this->setFechaRegistro(usuario.getFechaRegistro());
    this->setEdad(usuario.getEdad());

    return *this;
}

ostream& operator<<(ostream& archivo, const Usuario& usuario) {
    archivo << "Cuenta: " << usuario.getCuenta() << endl;
    archivo << "Nombre: " << usuario.getNombre() << endl;
    archivo << "Correo: " << usuario.getCorreo() << endl;
    archivo << "Facultad: " << usuario.getFacultad() << endl;
    archivo << "Fecha de Registro: " << usuario.getFechaRegistro() << endl;
    archivo << "Edad: " << usuario.getEdad() << endl;

    return archivo;
}

Usuario::~Usuario() {
    delete[] this->cuenta;
    delete[] this->nombre;
    delete[] this->correo;
    delete[] this->facultad;
}
