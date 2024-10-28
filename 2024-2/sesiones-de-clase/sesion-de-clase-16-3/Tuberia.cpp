/* 
 * File:   Tuberia.cpp
 * Author: erichuiza
 * 
 * Created on October 25, 2024, 4:10 PM
 */

#include "Tuberia.h"

Tuberia::Tuberia() : Cilindro() {
    radio2 = {};
}

Tuberia::Tuberia(double radio, double altura, double radio2) : Cilindro(radio, altura) {
    this->radio2 = radio2;
}

Tuberia::Tuberia(const Tuberia& orig) {
    *this = orig;
}

double Tuberia::getRadio2() const {
    return radio2;
}

double Tuberia::calcularArea() const {
    double c = calcularCircunferencia();
    double r = radio2;
    
    return c * (getAltura() + r);
}

void Tuberia::operator=(const Tuberia& orig) {
    Cilindro::operator=(orig);
    this->radio2 = orig.getRadio2();
}

void Tuberia::imprimir(ostream& os) const {
    Cilindro::imprimir(os);
    os << "Radio Interno: " << getRadio2() << endl;
}

Tuberia::~Tuberia() {
    cout << "Destructor de Tubería" << endl;
}
