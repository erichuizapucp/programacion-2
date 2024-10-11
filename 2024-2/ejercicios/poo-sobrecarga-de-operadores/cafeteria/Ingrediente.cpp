/* 
 * File:   Ingrediente.cpp
 * Author: erichuiza
 * 
 * Created on October 7, 2024, 12:42 PM
 */

#include "Ingrediente.h"

Ingrediente::Ingrediente() {
}

Ingrediente::Ingrediente(const Ingrediente& orig) {
    *this = orig;
}

Insumo* Ingrediente::getInsumo() const {
    return insumo;
}

char* Ingrediente::getUnidadMedida() const {
    return unidadMedida;
}

double Ingrediente::getCantidad() const {
    return cantidad;
}

void Ingrediente::setInsumo(Insumo* insumo) {
    this->insumo = insumo;
}

void Ingrediente::setUnidadMedida(const char* unidadMedida) {
    this->unidadMedida = new char[strlen(unidadMedida) + 1];
    strcpy(this->unidadMedida, unidadMedida);
}
    
void Ingrediente::setCantidad(const double cantidad) {
    this->cantidad = cantidad;
}

void Ingrediente::operator=(const Ingrediente& ingrediente) {
    this->setInsumo(ingrediente.getInsumo());
    this->setUnidadMedida(ingrediente.getUnidadMedida());
    this->setCantidad(ingrediente.getCantidad());
}

Ingrediente::~Ingrediente() {
    delete[] unidadMedida;
}
