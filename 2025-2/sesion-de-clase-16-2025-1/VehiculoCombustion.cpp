#include "VehiculoCombustion.h"

VehiculoCombustion::VehiculoCombustion() {
}

VehiculoCombustion::VehiculoCombustion(
    int cantRuedas, 
    double peso, 
    int capacidad, 
    int caballos, 
    int cantMotores, 
    int tipoCombustible, 
    bool gasolina, 
    bool petroleo, 
    bool GNV, 
    bool GLP) : VehiculoMotorizado(cantRuedas, peso, capacidad, caballos, cantMotores, tipoCombustible
) {
    this->gasolina = gasolina;
    this->petroleo = petroleo;
    this->GNV = GNV;
    this->GLP = GLP;
}

VehiculoCombustion::VehiculoCombustion(const VehiculoCombustion& orig) {
}

bool VehiculoCombustion::isGLP() const {
    return GLP;
}

void VehiculoCombustion::setGLP(bool GLP) {
    this->GLP = GLP;
}

bool VehiculoCombustion::isGNV() const {
    return GNV;
}

void VehiculoCombustion::setGNV(bool GNV) {
    this->GNV = GNV;
}

bool VehiculoCombustion::isGasolina() const {
    return gasolina;
}

void VehiculoCombustion::setGasolina(bool gasolina) {
    this->gasolina = gasolina;
}

bool VehiculoCombustion::isPetroleo() const {
    return petroleo;
}

void VehiculoCombustion::setPetroleo(bool petroleo) {
    this->petroleo = petroleo;
}

VehiculoCombustion::~VehiculoCombustion() {
}

