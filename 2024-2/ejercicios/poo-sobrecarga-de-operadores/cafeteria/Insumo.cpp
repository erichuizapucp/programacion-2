/* 
 * File:   Insumo.cpp
 * Author: erichuiza
 * 
 * Created on October 6, 2024, 7:09 PM
 */

#include "Insumo.h"

Insumo::Insumo() {
    cout << "Constructor Insumo" << endl;
    
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
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

void Insumo::setNombre(const char* nombre) {
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Insumo::setCantDisponible(const double cantDisponible) {
    this->cantDisponible = cantDisponible;
}

void Insumo::setCantRequerida(const double cantRequerida) {
    this->cantRequerida = cantRequerida;
}

void Insumo::setUnidadMedida(const char* unidadMedida) {
    this->unidadMedida = new char[strlen(unidadMedida) + 1];
    strcpy(this->unidadMedida, unidadMedida);
}

void Insumo::operator=(const Insumo& insumo) {
    this->setCodigo(insumo.getCodigo());
    this->setNombre(insumo.getNombre());
    this->setCantDisponible(insumo.getCantDisponible());
    this->setCantRequerida(insumo.getCantRequerida());
    this->setUnidadMedida(insumo.getUnidadMedida());
}

Insumo::~Insumo() {
    cout << "Destructor Insumo" << endl;
    
    delete[] codigo;
    delete[] nombre;
    delete[] unidadMedida;
}
