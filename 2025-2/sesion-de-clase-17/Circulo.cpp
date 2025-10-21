//
// Created by Eric Huiza on 10/20/25.
//

#include "Circulo.h"

Circulo::Circulo() {
    pi = 3.141592653589793;
    radio = 0.0;
}

Circulo::Circulo(double radio) : Circulo() {
    this->radio = radio;
}

Circulo::Circulo(const Circulo& origen) {
    this->pi = origen.pi;
    this->radio = origen.radio;
}

// double Circulo::getPi() const {
//     return this->pi;
// }
//
// double Circulo::getRadio() const {
//     return this->radio;
// }

double Circulo::calcularArea() const {
    return pi * radio * radio; // πr2
}

double Circulo::calcularPerimetro() const {
    return 2 * pi * radio;
}

Circulo::~Circulo() {

}