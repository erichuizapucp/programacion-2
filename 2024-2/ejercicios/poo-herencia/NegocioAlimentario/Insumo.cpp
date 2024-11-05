/* 
 * File:   Insumo.cpp
 * Author: erichuiza
 * 
 * Created on October 6, 2024, 7:09 PM
 */

#include "Insumo.h"

Insumo::Insumo() {
    codigo = {};
    nombre = {};
    cantDisponible = {};
    cantRequerida = {};
    unidadMedida = {};
}

Insumo::Insumo(const Insumo& orig) {
    *this = orig;
}

char* Insumo::getCodigo() const {
    return codigo;
}

char* Insumo::getNombre() const {
    return nombre;
}

double Insumo::getCantDisponible() const {
    return cantDisponible;
}

double Insumo::getCantRequerida() const {
    return cantRequerida;
}

char* Insumo::getUnidadMedida() const {
    return unidadMedida;
}

void Insumo::setCodigo(const char* codigo) {
    copiarCadena(this->codigo, codigo);
}

void Insumo::setNombre(const char* nombre) {
    copiarCadena(this->nombre, nombre);
}

void Insumo::setCantDisponible(const double cantDisponible) {
    this->cantDisponible = cantDisponible;
}

void Insumo::setCantRequerida(const double cantRequerida) {
    this->cantRequerida = cantRequerida;
}

void Insumo::setUnidadMedida(const char* unidadMedida) {
    copiarCadena(this->unidadMedida, unidadMedida);
}

bool Insumo::crear(ifstream& archivo) {
    if (!archivo.eof()) {
        this->codigo = leeCadena(archivo);
        this->nombre = leeCadena(archivo);
        
        archivo >> this->cantDisponible;
        this->cantRequerida = 0.00;
        archivo.ignore();
        
        this->unidadMedida = leeCadena(archivo, '\n');
        
        return true;
    }
    
    return false;
}

void Insumo::imprimir(ofstream&) const {
}

void Insumo::operator=(const Insumo& insumo) {
    this->setCodigo(insumo.getCodigo());
    this->setNombre(insumo.getNombre());
    this->setCantDisponible(insumo.getCantDisponible());
    this->setCantRequerida(insumo.getCantRequerida());
    this->setUnidadMedida(insumo.getUnidadMedida());
}

Insumo::~Insumo() {
    delete[] codigo;
    delete[] nombre;
    delete[] unidadMedida;
}
