#include "VehiculoHidrogeno.h"

VehiculoHidrogeno::VehiculoHidrogeno() {
}

VehiculoHidrogeno::VehiculoHidrogeno(
    int cantRuedas, 
    double peso, 
    int capacidad, 
    int caballos, 
    int cantMotores, 
    int tipoCombustible,
    int catalizador
) : VehiculoMotorizado(cantRuedas, peso, capacidad, caballos, cantMotores, tipoCombustible) {
    this->catalizador = catalizador;
}

VehiculoHidrogeno::VehiculoHidrogeno(const VehiculoHidrogeno& orig) {
}

int VehiculoHidrogeno::getCatalizador() const {
    return catalizador;
}

void VehiculoHidrogeno::setCatalizador(int catalizador) {
    this->catalizador = catalizador;
}

VehiculoHidrogeno::~VehiculoHidrogeno() {
}

