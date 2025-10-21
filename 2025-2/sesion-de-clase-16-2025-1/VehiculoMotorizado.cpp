#include "VehiculoMotorizado.h"

VehiculoMotorizado::VehiculoMotorizado() {
}

VehiculoMotorizado::VehiculoMotorizado(
    int cantRuedas, 
    double peso, 
    int capacidad, 
    int caballos, 
    int cantMotores, 
    int tipoCombustible
) : Carreta(cantRuedas, peso, capacidad, caballos) {
    this->cantMotores = cantMotores;
    this->tipoCombustible = tipoCombustible;
}

int VehiculoMotorizado::getCantMotores() const {
    return cantMotores;
}

void VehiculoMotorizado::setCantMotores(int cantMotores) {
    this->cantMotores = cantMotores;
}

int VehiculoMotorizado::getTipoCombustible() const {
    return tipoCombustible;
}

void VehiculoMotorizado::setTipoCombustible(int tipoCombustible) {
    this->tipoCombustible = tipoCombustible;
}

VehiculoMotorizado::VehiculoMotorizado(const VehiculoMotorizado& orig) {
}

VehiculoMotorizado::~VehiculoMotorizado() {
}

