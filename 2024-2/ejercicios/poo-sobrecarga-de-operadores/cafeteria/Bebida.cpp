/* 
 * File:   Bebida.cpp
 * Author: erichuiza
 * 
 * Created on October 6, 2024, 7:09 PM
 */

#include "Bebida.h"

Bebida::Bebida() {
    codigo = {};
    nombre = {};
    descripcion = {};
    tipo = {};
    precio = {};
    cantVent = {};
    ingredientes = {};
    cantIngredientes = {};
}

Bebida::Bebida(const Bebida& orig) {
    *this = orig;
}

char* Bebida::getCodigo() const {
    return codigo;
}

char* Bebida::getNombre() const {
    return nombre;
}

char* Bebida::getDescripcion() const {
    return descripcion;
}

char Bebida::getTipo() const {
    return tipo;
}

double Bebida::getPrecio() const {
    return precio;
}

int Bebida::getCantVent() const {
    return cantVent;
}

bool Bebida::getDisponible() const {
    return disponible;
}

const char* Bebida::getNombreTipoBebida() const {
    const char* tipoStr;
    switch (tipo) {
        case 'C':
            tipoStr = "Café";
            break;
        case 'T':
            tipoStr = "Té";
            break;
        case 'H':
            tipoStr = "Chocolate";
            break;
        case 'I':
            tipoStr = "Infusión";
            break;
        default:
            tipoStr = "Café";

    }
    return tipoStr;
}

Ingrediente* Bebida::getIngredientes() const {
    return ingredientes;
}

int Bebida::getCantIngredientes() const {
    return cantIngredientes;
}

void Bebida::setCodigo(const char* codigo) {
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

void Bebida::setNombre(const char* nombre) {
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Bebida::setDescripcion(const char* descripcion) {
    this->descripcion = new char[strlen(descripcion) + 1];
    strcpy(this->descripcion, descripcion);
}

void Bebida::setTipo(const char tipo) {
    this->tipo = tipo;
}

void Bebida::setPrecio(const double precio) {
    this->precio = precio;
}

void Bebida::setCantVent(const int cantVent) {
    this->cantVent = cantVent;
}

void Bebida::setDisponible(const bool disponible) {
    this->disponible = disponible;
}

void Bebida::operator=(const Bebida& bebida) {
    this->setCodigo(bebida.getCodigo());
    this->setNombre(bebida.getNombre());
    this->setDescripcion(bebida.getDescripcion());
    this->setPrecio(bebida.getPrecio());
    this->setTipo(bebida.getTipo());
    this->setCantVent(bebida.getCantVent());
    this->setDisponible(bebida.getDisponible());
}

void Bebida::operator<<(const Ingrediente ingrediente) {
    incrementarIngredientes();
    ingredientes[cantIngredientes++] = ingrediente;
}

void Bebida::incrementarIngredientes() {
    if (ingredientes == nullptr) {
        ingredientes = new Ingrediente[cantIngredientes + 1] {};
    }
    else {
        Ingrediente* aux = new Ingrediente[cantIngredientes + 1] {};
        for (int i = 0; i < cantIngredientes; i++) {
            aux[i] = ingredientes[i];
        }
        delete[] ingredientes;
        ingredientes = aux;
    }
}

void Bebida::verificarDisponibilidad() {
    for (int i = 0; i < cantIngredientes; i++) {
        Ingrediente ingrediente = ingredientes[i];
        Insumo* insumo = ingrediente.getInsumo();
        
        double cantidadPorBebida = ingrediente.getCantidad();
        double cantidadDisponible = insumo->getCantDisponible();
        double cantidadRequerida = insumo->getCantRequerida();
        
        double nuevaCantidadRequerida = cantidadRequerida + ((cantidadPorBebida / 1000.00) * cantVent);
        
        if (cantidadDisponible < nuevaCantidadRequerida) {
            disponible = false;
            break;
        }
        
        insumo->setCantRequerida(nuevaCantidadRequerida);
    }
}

Bebida::~Bebida() {
    delete[] codigo;
    delete[] nombre;
    delete[] descripcion;
}
