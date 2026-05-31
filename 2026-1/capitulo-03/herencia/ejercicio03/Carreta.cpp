#include "Carreta.h"

Carreta::Carreta() {
}

Carreta::Carreta(int cantRuedas, double peso, int capacidad, int caballos) {
    this->cantRuedas = cantRuedas;
    this->peso = peso;
    this->capacidad = capacidad;
    this->caballos = caballos;
}

Carreta::Carreta(const Carreta& orig) {
}

int Carreta::getCaballos() const {
    return caballos;
}

void Carreta::setCaballos(int caballos) {
    this->caballos = caballos;
}

int Carreta::getCantRuedas() const {
    return cantRuedas;
}

void Carreta::setCantRuedas(int cantRuedas) {
    this->cantRuedas = cantRuedas;
}

int Carreta::getCapacidad() const {
    return capacidad;
}

void Carreta::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
}

double Carreta::getPeso() const {
    return peso;
}

void Carreta::setPeso(double peso) {
    this->peso = peso;
}


Carreta::~Carreta() {
}

