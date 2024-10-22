/* 
 * File:   Circulo.cpp
 * Author: erichuiza
 * 
 * Created on October 21, 2024, 8:48 AM
 */

#include "Circulo.h"

Circulo::Circulo() {
    radio = {};
}

Circulo::Circulo(double radio) {
    this->radio = radio;
}

Circulo::Circulo(const Circulo& orig) {
    *this = orig;
}

double Circulo::getRadio() const {
    return radio;
}

double Circulo::calcularArea() const {
    return 3.141516 * radio * radio;
}

double Circulo::calcularCircunferencia() const {
    return 2 * 3.141516 * radio;
}

void Circulo::operator=(const Circulo& orig) {
    radio = orig.radio;
}

void Circulo::imprimir(ostream& os) const {
    os << "Radio: " << getRadio() << endl 
        << "Circunferencia: " << calcularCircunferencia() << endl
        << "Area: " << calcularArea() << endl;
}

ostream& operator<<(ostream& os, const Circulo& c) {
    c.imprimir(os);
    return os;
}

Circulo::~Circulo() {
}

