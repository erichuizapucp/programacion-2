#include "Conductor.h"

bool Conductor::cargarDatos(ifstream& archivo) {
    if (!archivo.eof() && archivo >> codigo) {
        archivo.ignore();
        getline(archivo, nombres, ',');
        getline(archivo, apellidoPaterno, ',');
        getline(archivo, apellidoMaterno, ',');
        getline(archivo, numLicencia, ',');
        
        archivo >> codigoLicencia;
        archivo.ignore();
        
        archivo >> puntos;
        archivo.ignore();
        
        return true;
    }
    
    return false; 
}

void Conductor::imprimir(ostream& archivo) const {
    archivo 
            << setw(5) << codigo
            << setw(30) << nombres
            << setw(20) << apellidoPaterno
            << setw(20) << apellidoMaterno
            << setw(10) << numLicencia
            << setw(20) << licencia.getNombre()
            << setw(15) << puntos
            << endl;
}

bool Conductor::operator<(const Conductor& c) const {
//    return nombres < c.nombres;
    return codigo < c.codigo;
}

string Conductor::getApellidoMaterno() const {
    return apellidoMaterno;
}

void Conductor::setApellidoMaterno(string apellidoMaterno) {
    this->apellidoMaterno = apellidoMaterno;
}

string Conductor::getApellidoPaterno() const {
    return apellidoPaterno;
}

void Conductor::setApellidoPaterno(string apellidoPaterno) {
    this->apellidoPaterno = apellidoPaterno;
}

int Conductor::getCodigo() const {
    return codigo;
}

void Conductor::setCodigo(int codigo) {
    this->codigo = codigo;
}

int Conductor::getCodigoLicencia() const {
    return codigoLicencia;
}

void Conductor::setCodigoLicencia(int codigoLicencia) {
    this->codigoLicencia = codigoLicencia;
}

Licencia Conductor::getLicencia() const {
    return licencia;
}

void Conductor::setLicencia(Licencia licencia) {
    this->licencia = licencia;
}

string Conductor::getNombres() const {
    return nombres;
}

void Conductor::setNombres(string nombres) {
    this->nombres = nombres;
}

string Conductor::getNumLicencia() const {
    return numLicencia;
}

void Conductor::setNumLicencia(string numLicencia) {
    this->numLicencia = numLicencia;
}

int Conductor::getPuntos() const {
    return puntos;
}

void Conductor::setPuntos(int puntos) {
    this->puntos = puntos;
}
