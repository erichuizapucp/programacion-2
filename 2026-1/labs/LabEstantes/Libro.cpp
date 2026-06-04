#include "Libro.h"
#include <cstring>

Libro::Libro() {
    codigo = nullptr;
    nombre = nullptr;
    ancho = 0;
    alto = 0;
    peso = 0;
    colocado = false;
}

Libro::Libro(const Libro& otro) {
    codigo = nullptr;
    nombre = nullptr;
    *this = otro;
}

Libro& Libro::operator=(const Libro& otro) {
    if (this == &otro) {
        return *this;
    }
    setCodigo(otro.codigo);
    setNombre(otro.nombre);
    ancho = otro.ancho;
    alto = otro.alto;
    peso = otro.peso;
    colocado = otro.colocado;
    return *this;
}

char* Libro::getCodigo() const { return codigo; }
char* Libro::getNombre() const { return nombre; }
int Libro::getAncho() const { return ancho; }
int Libro::getAlto() const { return alto; }
double Libro::getPeso() const { return peso; }
bool Libro::getColocado() const { return colocado; }

void Libro::setCodigo(const char* nuevo) {
    delete[] codigo;
    if (nuevo == nullptr) {
        codigo = nullptr;
        return;
    }
    codigo = new char[strlen(nuevo) + 1];
    strcpy(codigo, nuevo);
}

void Libro::setNombre(const char* nuevo) {
    delete[] nombre;
    if (nuevo == nullptr) {
        nombre = nullptr;
        return;
    }
    nombre = new char[strlen(nuevo) + 1];
    strcpy(nombre, nuevo);
}

void Libro::setAncho(int ancho) {
    this->ancho = ancho;
}

void Libro::setAlto(int alto) {
    this->alto = alto;
}

void Libro::setPeso(double peso) {
    this->peso = peso;
}

void Libro::setColocado(bool valor) {
    colocado = valor;
}

Libro::~Libro() {
    delete[] codigo;
    delete[] nombre;
}
