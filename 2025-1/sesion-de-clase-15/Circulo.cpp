/* 
 * File:   Circulo.cpp
 * Author: erichuiza
 * 
 * Created on May 16, 2025, 5:37 PM
 */

#include "Circulo.h"

Circulo::Circulo() {
}

Circulo::Circulo(double radio) {
    this->radio = radio;
}

Circulo::Circulo(const Circulo& orig) {
}

double Circulo::getRadio() const {
    return this->radio;
}

void Circulo::setRadio(double radio) {
    this->radio = radio;
}
    
double Circulo::calcularArea() {
    return 3.14 * this->radio * this->radio;
}

void Circulo::imprimirArea() {
    cout << "El área del círculo es: " << this->calcularArea() << endl;
}

Circulo::~Circulo() {
}

