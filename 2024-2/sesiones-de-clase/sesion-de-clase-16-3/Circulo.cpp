/* 
 * File:   Circulo.cpp
 * Author: erichuiza
 * 
 * Created on October 21, 2024, 3:38 PM
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

void Circulo::operator=(const Circulo& orig) {
    this->radio = orig.getRadio();
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

void Circulo::imprimir(ostream& os) const {
    os << "Radio: " << getRadio() << endl;
    os << "Area: " << calcularArea() << endl;
    os << "Circunferencia: " << calcularCircunferencia() << endl;
}

Circulo::~Circulo() {
    cout << "Destructor de Circulo" << endl;
}
