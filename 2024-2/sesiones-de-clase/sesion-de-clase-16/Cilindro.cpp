/* 
 * File:   Cilindro.cpp
 * Author: erichuiza
 * 
 * Created on October 21, 2024, 10:22 AM
 */

#include "Cilindro.h"
#include "Circulo.h"

Cilindro::Cilindro() : Circulo() {
    altura = {};
}

Cilindro::Cilindro(double radio, double altura) : Circulo(radio) {
    this->altura = altura;
}

Cilindro::Cilindro(const Cilindro& orig) : Circulo(orig) {
    *this = orig;
}

void Cilindro::operator=(const Cilindro& orig) {
    Circulo::operator=(orig);
    altura = orig.altura;
}

double Cilindro::calcularArea() const {
    double radio = getRadio();
    return calcularCircunferencia() * (radio + altura);
}

void Cilindro::imprimir(ostream& os) const {
    Circulo::imprimir(os);
    os << "Altura: " << altura << endl;
    os << "Area del Cilindro: " << calcularArea() << endl;
}

ostream& operator<<(ostream& os, const Cilindro& c) {
    c.imprimir(os);
    return os;
}

Cilindro::~Cilindro() {
}
