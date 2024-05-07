
#include "Circulo.h"
#include "Cilindro.h"

Cilindro::Cilindro(double r, double h) : Circulo(r), h(h) {
//    this->h = h;
}

double Cilindro::calcularArea() {
    return Circulo::calcularArea() * this->h;
}