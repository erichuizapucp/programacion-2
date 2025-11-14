#include "Vehiculo.h"

bool Vehiculo::cargarDatos(ifstream& archivo) {
    if (!archivo.eof() && archivo >> codigo) {
        archivo.ignore();
        getline(archivo, placa, ',');
        getline(archivo, marca, ',');
        getline(archivo, modelo, ',');
        archivo >> anho;
        archivo.ignore();
        
        return true;
    }
    
    return false;
}

void Vehiculo::imprimir(ostream& archivo) const {
    archivo 
            << setw(5) << codigo
            << setw(10) << placa
            << setw(15) << marca
            << setw(15) << modelo
            << setw(10) << anho
            << endl;
}

int Vehiculo::getAnho() const {
    return anho;
}

void Vehiculo::setAnho(int anho) {
    this->anho = anho;
}

int Vehiculo::getCodigo() const {
    return codigo;
}

void Vehiculo::setCodigo(int codigo) {
    this->codigo = codigo;
}

string Vehiculo::getMarca() const {
    return marca;
}

void Vehiculo::setMarca(string marca) {
    this->marca = marca;
}

string Vehiculo::getModelo() const {
    return modelo;
}

void Vehiculo::setModelo(string modelo) {
    this->modelo = modelo;
}

string Vehiculo::getPlaca() const {
    return placa;
}

void Vehiculo::setPlaca(string placa) {
    this->placa = placa;
}