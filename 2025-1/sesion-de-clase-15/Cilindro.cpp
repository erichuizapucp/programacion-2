/* 
 * File:   Cilindro.cpp
 * Author: erichuiza
 * 
 * Created on May 16, 2025, 5:44 PM
 */

#include "Cilindro.h"

Cilindro::Cilindro() {
}

Cilindro::Cilindro(double radio, double altura) 
    : Circulo(radio) {
    
    this->altura = altura;
}

Cilindro::Cilindro(const Cilindro& orig) {
}

double Cilindro::getAltura() const {
    return this->altura;
}

void Cilindro::setAltura(double altura) {
    this->altura = altura;
}
    
double Cilindro::calcularArea() {
    return 2 * 3.14 * this->altura + 2 * Circulo::calcularArea();
}

void Cilindro::imprimirArea() {
    Circulo::imprimirArea();
    cout << "Area del cilindro es: " << this->calcularArea() << endl;
}

Cilindro::~Cilindro() {
}

