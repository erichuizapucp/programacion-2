/* 
 * File:   Cilindro.cpp
 * Author: erichuiza
 * 
 * Created on October 21, 2024, 4:01 PM
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

double Cilindro::getAltura() const {
    return altura;
}

double Cilindro::calcularArea() const {
    double c = calcularCircunferencia();
    double r = getRadio();
    
    return c * (altura + r);
}

void Cilindro::operator=(const Cilindro& orig) {
    Circulo::operator=(orig);
    this->altura = orig.getAltura();
}

void Cilindro::imprimir(ostream& os) const {
    Circulo::imprimir(os);
    os << "Altura: " << getAltura() << endl;
    os << "Area del Cilindro: " << calcularArea() << endl;
}

Cilindro::~Cilindro() {
    cout << "Destructor de Cilindro" << endl;
}
