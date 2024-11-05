/* 
 * File:   Producto.cpp
 * Author: erichuiza
 * 
 * Created on October 17, 2024, 11:47 AM
 */

#include "Producto.h"

Producto::Producto() {
    codigo = {};
    nombre = {};
    descripcion = {};
    precio = {};
    cantVentDiaria = {};
    disponible = {};
    ingredientes = {};
}

Producto::Producto(const Producto& orig) {
    *this = orig;
}

char* Producto::getCodigo() const {
    return codigo;
}

char* Producto::getNombre() const {
    return nombre;
}

char* Producto::getDescripcion() const {
    return descripcion;
}

double Producto::getPrecio() const {
    return precio;
}

int Producto::getCantVentDiaria() const {
    return cantVentDiaria;
}

bool Producto::getDisponible() const {
    return disponible;
}

const Lista<Ingrediente>& Producto::getIngredientes() const {
    return ingredientes;
}

void Producto::setCodigo(const char* codigo) {
    Producto::copiarCadena(this->codigo, codigo);
}

void Producto::setNombre(const char* nombre) {
    Producto::copiarCadena(this->nombre, nombre);
}

void Producto::setDescripcion(const char* descripcion) {
    Producto::copiarCadena(this->descripcion, descripcion);
}

void Producto::setPrecio(const double precio) {
    this->precio = precio;
}

void Producto::setCantVentDiaria(const int cantVentDiaria) {
    this->cantVentDiaria = cantVentDiaria;
}

void Producto::setDisponible(const bool disponible) {
    this->disponible = disponible;
}

void Producto::setIngredientes(const Lista<Ingrediente>& ingredientes) {
    this->ingredientes = ingredientes;
}

bool Producto::crear(ifstream& archivo) {
    char* codigo;
    char* nombre;
    char* descripcion;
    char tipo;
    double precio;
    int cantVent;
    
    if (!archivo.eof()) {
        codigo = leeCadena(archivo);
        nombre = leeCadena(archivo);
        descripcion = leeCadena(archivo);
        archivo >> tipo;
        archivo.ignore();
        archivo >> precio;
        archivo.ignore();
        archivo >> cantVent;
        archivo.ignore();
        
        this->codigo = codigo;
        this->nombre = nombre;
        this->descripcion = descripcion;
//        this->tipo = tipo;
        this->precio = precio;
        this->cantVentDiaria = cantVent;
        this->disponible = true;
        
        return true;
    }
    
    return false;
}

void Producto::imprimir(ofstream& archivo) const {
    archivo << nombre << endl;
    archivo << descripcion << endl;
    archivo << "Precio: S/ " << fixed << setprecision(2) << precio << endl;
    archivo << "Disponible: " << (disponible ? "Si" : "No") << endl;
}

void Producto::operator=(const Producto& orig) {
    setCodigo(orig.getCodigo());
    setNombre(orig.getNombre());
    setDescripcion(orig.getDescripcion());
    setPrecio(orig.getPrecio());
    setCantVentDiaria(orig.getCantVentDiaria());
    setDisponible(orig.getDisponible());
    setIngredientes(orig.getIngredientes());
}

//bool operator>>(ifstream& archivo, Producto& producto) {
//    return producto.crear(archivo);
//}

ofstream& operator<<(ofstream& archivo, const Producto& producto) {
    producto.imprimir(archivo);
    return archivo;
}

Producto::~Producto() {
    delete[] codigo;
    delete[] nombre;
    delete[] descripcion;
}
