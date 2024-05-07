#include "Circulo.h"

Circulo::Circulo(double r) {
    this->r = r;
}

double Circulo::calcularArea() {
    return 3.14*r*r;
}