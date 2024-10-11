/* 
 * File:   Cafeteria.cpp
 * Author: erichuiza
 * 
 * Created on October 6, 2024, 7:08 PM
 */

#include "Cafeteria.h"
#include "funciones.h"

Cafeteria::Cafeteria() {
    inventario = {};
    menu = {};
}

Cafeteria::Cafeteria(const Cafeteria& orig) {
}

void Cafeteria::cargarInventario(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    inventario.cargarInsumos(archivo);
}   

void Cafeteria::cargarMenu(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    menu.cargarBebidas(archivo);
}

void Cafeteria::actualizarMenu(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    while (cargarIngrediente(archivo));
    menu.verificar();
}

bool Cafeteria::cargarIngrediente(ifstream& archivo) {
    char* codigoBebida;
    char* codigoInsumo;
    double cantidad;
    char* unidadMedida;
    
    if (!archivo.eof()) {
        codigoBebida = leeCadena(archivo);
        codigoInsumo = leeCadena(archivo);
        archivo >> cantidad;
        archivo.ignore();
        unidadMedida = leeCadena(archivo, '\n');
        
        Insumo* insumo = inventario.buscarInsumo(codigoInsumo);
        Ingrediente ingrediente;
        ingrediente.setInsumo(insumo);
        ingrediente.setCantidad(cantidad);
        ingrediente.setUnidadMedida(unidadMedida);
        
        Bebida* bebida = menu.buscarBebida(codigoBebida);
        *bebida << ingrediente;
        
        return true;
    }
    
    return false;
}

void Cafeteria::reporteMenu(const char* nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out);
    archivo << menu;
}

Cafeteria::~Cafeteria() {
}
