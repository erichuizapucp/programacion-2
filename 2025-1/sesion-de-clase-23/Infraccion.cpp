/* 
 * File:   Infraccion.cpp
 * Author: erichuiza
 * 
 * Created on June 23, 2025, 11:22 AM
 */

#include "Infraccion.h"
#include "Licencia.h"

map<string, GRAVEDAD_INFRACCION> Infraccion::infraccionMap = {
    { "LEVE", GRAVEDAD_INFRACCION::LEVE }, 
    { "GRAVE", GRAVEDAD_INFRACCION::GRAVE }, 
    { "MUY_GRAVE", GRAVEDAD_INFRACCION::MUY_GRAVE }
};

bool Infraccion::cargarDatos(ifstream& archivo) {
    if (!archivo.eof() && archivo >> codigo) {
        archivo.ignore();
        getline(archivo, descripcion, ',');
        archivo >> monto;
        archivo.ignore();
        gravedad = leerGravedad(archivo);
        archivo.ignore();
        archivo >> puntos;
        archivo.ignore();
        
        return true;
    }
    
    return false;
}

GRAVEDAD_INFRACCION Infraccion::leerGravedad(ifstream& archivo) {
    string gravedad;
    getline(archivo, gravedad, ',');
    
//    Infraccion::infraccionMap::iterator
    auto it = infraccionMap.find(gravedad);
    if (it != infraccionMap.end()) {
        return it->second;
    }
    
    return GRAVEDAD_INFRACCION::LEVE;
}

void Infraccion::imprimir(ostream& archivo) const {
    archivo 
            << setw(5) << codigo 
            << setw(100) << descripcion 
            << setw(20) << fixed << setprecision(2) << monto 
            << setw(20) << gravedad 
            << setw(20) << puntos 
            << endl;
}

int Infraccion::getCodigo() const {
    return codigo;
}

void Infraccion::setCodigo(int codigo) {
    this->codigo = codigo;
}

string Infraccion::getDescripcion() const {
    return descripcion;
}

void Infraccion::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

GRAVEDAD_INFRACCION Infraccion::getGravedad() const {
    return gravedad;
}

void Infraccion::setGravedad(GRAVEDAD_INFRACCION gravedad) {
    this->gravedad = gravedad;
}

double Infraccion::getMonto() const {
    return monto;
}

void Infraccion::setMonto(double monto) {
    this->monto = monto;
}

int Infraccion::getPuntos() const {
    return puntos;
}

void Infraccion::setPuntos(int puntos) {
    this->puntos = puntos;
}
