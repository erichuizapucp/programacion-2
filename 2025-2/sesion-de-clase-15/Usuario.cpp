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
    this->publicaciones = nullptr;
    this->cantPublicaciones = 0;
    this->capacidad = 0;
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

Publicacion* Usuario::getPublicaciones() const {
    return publicaciones;
}

int Usuario::getCantPublicaciones() const {
    return cantPublicaciones;
}

int Usuario::getCapacidad() const {
    return capacidad;
}

Usuario& Usuario::operator+=(const Publicacion& publicacion) {
    if (cantPublicaciones == capacidad) {
        incrementar();
    }
    publicaciones[cantPublicaciones++] = publicacion;
    return *this;
}

void Usuario::incrementar() {
    capacidad += 5;
    if (publicaciones == nullptr) {
        publicaciones = new Publicacion[capacidad];
    }
    else {
        Publicacion* aux = new Publicacion[capacidad];
        for (int i = 0; i < cantPublicaciones; i++) {
            aux[i] = publicaciones[i];
        }
        delete[] publicaciones;
        publicaciones = aux;
    }
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

Publicacion& Usuario::operator[](int indice) const {
    return publicaciones[indice];
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
    const char* cuenta = usuario.getCuenta();
    const char* nombre = usuario.getNombre();
    const char* correo = usuario.getCorreo();
    const char* facultad = usuario.getFacultad();
    const int fecha = usuario.getFechaRegistro();
    const int edad = usuario.getEdad();

    archivo << setfill('=') << setw(40) << "" << setfill(' ') << endl;
    archivo << "REPORTE DE USUARIO" << endl;
    archivo << setfill('=') << setw(40) << "" << setfill(' ') << endl;

    archivo << left
            << setw(10) << "Cuenta:" << setw(15) << cuenta   << endl
            << setw(10) << "Nombre:" << setw(20) << nombre   << endl
            << setw(10) << "Correo:" << setw(25) << correo   << endl
            << setw(10) << "Facultad:" << setw(15) << facultad << endl
            << setw(10) << "Fecha: ";
    usuario.imprimirFecha(archivo);
    archivo << endl;
    archivo << setw(10) << "Edad:" << setw(3)  << edad
            << endl;

    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    archivo << "PUBLICACIONES REALIZADAS" << endl;
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    for (int i = 0; i < usuario.getCantPublicaciones(); i++) {
        Publicacion& publication = usuario[i];
        archivo << publication << endl;
    }

    return archivo;
}

void Usuario::imprimirFecha(ostream& archivo) const {
    const int anho  = fechaRegistro / 10000;
    const int mes   = (fechaRegistro / 100) % 100;
    const int dia   = fechaRegistro % 100;

    archivo << (dia / 10) << (dia % 10) << "-"
            << (mes / 10) << (mes % 10) << "-"
            << (anho / 1000) % 10
            << (anho / 100) % 10
            << (anho / 10) % 10
            << anho % 10;
}

Usuario::~Usuario() {
    delete[] this->cuenta;
    delete[] this->nombre;
    delete[] this->correo;
    delete[] this->facultad;
}
