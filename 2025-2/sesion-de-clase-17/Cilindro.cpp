//
// Created by Eric Huiza on 10/20/25.
//

#include "Cilindro.h"

Cilindro::Cilindro() {
    altura = 0.0;
}

Cilindro::Cilindro(double radio, double altura)
    : Circulo(radio), altura(altura) {
}

Cilindro::Cilindro(const Cilindro& origen) : Circulo(origen) {
    this->altura = origen.altura;
}

double Cilindro::calcularArea() const {
    return calcularPerimetro() * altura
        + 2 * Circulo::calcularArea();
}

Cilindro::~Cilindro() {

}