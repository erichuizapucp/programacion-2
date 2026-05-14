//
// Created by Eric Huiza on 5/13/26.
//

#include "Cadena.h"

Cadena::Cadena() {
    cadena = nullptr;
    longitud = 0;
    capacidad = 0;
}

Cadena::Cadena(const char* cadena) : Cadena() {
    this->assign(cadena);
    // longitud = strlen(cadena);
    // capacidad = longitud + 1;
    // delete[] this->cadena;
    // this->cadena = new char[capacidad];
    // strcpy(this->cadena, cadena);
}

Cadena::Cadena(int capacidad) : Cadena() {
    this->capacidad = capacidad;
    delete[] cadena;
    cadena = new char[capacidad];
    longitud = 0;
}

Cadena::Cadena(const Cadena& origin) : Cadena() {
    *this = origin;
}

void Cadena::assign(const char* origin) {
    int capRequerida = strlen(origin) + 1;
    int lenOrigin = strlen(origin);
    if (capacidad < capRequerida) {
        capacidad = lenOrigin + int(lenOrigin * 0.3);
    }
    delete[] this->cadena;
    this->cadena = new char[capacidad];
    strcpy(this->cadena, origin);
    longitud = strlen(this->cadena);
}

void Cadena::assign(const Cadena& origin) {
    const char* cadena = origin.cadena;
    this->assign(cadena);
}

void Cadena::append(const char* origin) {
    int capTotal = this->longitud + strlen(origin) + 1;
    Cadena temp = *this;
    delete[] this->cadena;
    this->cadena = nullptr;
    char* nuevaCadena = new char[capTotal];
    strcpy(nuevaCadena, temp.cadena);
    strcat(nuevaCadena, origin);

    this->assign(nuevaCadena);
}

void Cadena::append(const Cadena& origin) {
    const char* cadena = origin.cadena;
    this->append(cadena);
}

void Cadena::swap(Cadena& origin) {
    if (this != &origin) {
        Cadena temp = *this;
        *this = origin;
        origin = temp;
    }
};

Cadena& Cadena::operator=(const Cadena& origin) {
    if (this != &origin) {
        *this = origin.cadena;
    }
    return *this;

    // this->capacidad = origin.capacidad;
    // this->longitud = origin.longitud;
    // delete[] this->cadena;
    // this->cadena = new char[capacidad];
    // strcpy(this->cadena, origin.cadena);
    // return *this;
}

int Cadena::compare(const char* origin) const {
    return strcmp(this->cadena, origin);
}

int Cadena::compare(const Cadena& origin) const {
    const char* cadena = origin.cadena;
    return this->compare(cadena);
}

Cadena& Cadena::operator=(const char* origin) {
    this->assign(origin);
    return *this;
}

Cadena Cadena::operator+(const Cadena& origin) {
    Cadena resultado = *this;
    resultado.append(origin);
    return resultado;
}

bool Cadena::operator>(const Cadena& origin) const {
    return this->compare(origin) > 0;
}

bool Cadena::operator<(const Cadena& origin) const {
    return this->compare(origin) < 0;
}

bool Cadena::operator>=(const Cadena& origin) const {
    return this->compare(origin) >= 0;
}

bool Cadena::operator<=(const Cadena& origin) const {
    return this->compare(origin) <= 0;
}

bool Cadena::operator==(const Cadena& origin) const {
    return this->compare(origin) == 0;
}

char* Cadena::getCadena() const {
    return this->cadena;
}

int Cadena::getLongitud() const {
    return this->longitud;
}

ifstream& operator>>(ifstream& archivo, Cadena& cadena) {
    Cadena apellidoPaterno = leerCadena(archivo);
    if (archivo && apellidoPaterno.getLongitud() > 0) {
        Cadena apellidoMaterno = leerCadena(archivo);
        Cadena nombre = leerCadena(archivo, '\n');
        cadena = apellidoPaterno +
            "/" + apellidoMaterno + "/" + nombre;
    }
    return archivo;
}

ostream& operator<<(ostream& os, const Cadena& cadena) {
    os << cadena.getCadena() << endl;
    return os;
}

char* leerCadena(ifstream& archivo, char delim) {
    char buffer[200];
    archivo.getline(buffer, 200, delim);
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

Cadena::~Cadena() {
    delete[] cadena;
}