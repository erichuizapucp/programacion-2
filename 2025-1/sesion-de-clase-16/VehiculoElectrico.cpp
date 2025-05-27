#include "VehiculoElectrico.h"

VehiculoElectrico::VehiculoElectrico() {
}

VehiculoElectrico::VehiculoElectrico(
    int cantRuedas, 
    double peso, 
    int capacidad, 
    int caballos, 
    int cantMotores, 
    int tipoCombustible, 
    int tipoBateria, 
    int cantCeldas
): VehiculoMotorizado(cantRuedas, peso, capacidad, caballos, cantMotores, tipoCombustible) {
    this->tipoBateria = tipoBateria;
    this->cantCeldas = cantCeldas;
}

int VehiculoElectrico::getCantCeldas() const {
    return cantCeldas;
}

void VehiculoElectrico::setCantCeldas(int cantCeldas) {
    this->cantCeldas = cantCeldas;
}

int VehiculoElectrico::getTipoBateria() const {
    return tipoBateria;
}

void VehiculoElectrico::setTipoBateria(int tipoBateria) {
    this->tipoBateria = tipoBateria;
}

VehiculoElectrico::VehiculoElectrico(const VehiculoElectrico& orig) {
}

VehiculoElectrico::~VehiculoElectrico() {
}

