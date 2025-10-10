//
// Created by Eric Huiza on 10/10/25.
//

#include "UsuarioEstandard.h"

UsuarioEstandard::UsuarioEstandard() {
    this->contactos = nullptr;
}

UsuarioEstandard::UsuarioEstandard(const UsuarioEstandard& origen)
    : Usuario(origen), contactos(nullptr) {

    *this = origen;
}

UsuarioEstandard::UsuarioEstandard(
    char* cuenta,
    char* nombre,
    char* email,
    char* facultad)
    : Usuario(cuenta, nombre, email, facultad),
      contactos(nullptr) {
}

UsuarioEstandard::UsuarioEstandard(int fechaRegistro, int edad)
    : Usuario(fechaRegistro, edad),
      contactos(nullptr) {
}

UsuarioEstandard::UsuarioEstandard(char* cuenta,
    char* nombre,
    char* email,
    char* facultad,
    int fechaRegistro,
    int edad)
    : Usuario(cuenta, nombre, email, facultad, fechaRegistro, edad),
      contactos(nullptr) {
}

void UsuarioEstandard::setContactos(char** contactos) {
    delete[] this->contactos;
    this->contactos = nullptr;

    int num = 0;
    for (; contactos[num]; num++) {}

    this->contactos = new char*[num + 1] {};
    for (int i = 0; i < num; i++) {
        this->contactos[i] = new char[strlen(contactos[i]) + 1];
        strcpy(this->contactos[i], contactos[i]);
    }
}

char** UsuarioEstandard::getContactos() const {
    return contactos;
}

UsuarioEstandard& UsuarioEstandard::operator=(const UsuarioEstandard& origin) {
    if (this == &origin) {
        return *this;
    }

    Usuario::operator=(origin);
    this->setContactos(origin.getContactos());

    return *this;
}

UsuarioEstandard& UsuarioEstandard::operator+=(const Publicacion& publicacion) {
    Usuario::operator+=(publicacion);
    return *this;
}

istream& UsuarioEstandard::leer(istream& archivo) {
    if (!Usuario::leer(archivo)) {
        return archivo;
    }

    char** cuentas;
    archivo.ignore(); // ignorar el [
    leerCuentas(archivo, cuentas);
    archivo.ignore();

    this->setContactos(cuentas);

    return archivo;
}

ostream& UsuarioEstandard::imprimir(ostream& archivo) const {
    Usuario::imprimir(archivo);
    return archivo;
}

istream& operator>>(istream& archivo, UsuarioEstandard& usuario) {
    return usuario.leer(archivo);
}

ostream& operator<<(ostream& archivo, const UsuarioEstandard& usuario) {
    return usuario.imprimir(archivo);
}

UsuarioEstandard::~UsuarioEstandard() {
    delete[] contactos;
}
