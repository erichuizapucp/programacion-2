/* 
 * File:   Inventario.cpp
 * Author: erichuiza
 * 
 * Created on October 7, 2024, 10:55 AM
 */

#include "Inventario.h"
#include "funciones.h"

Inventario::Inventario() {
}

Inventario::Inventario(const Inventario& orig) {
}

void Inventario::cargarInsumos(ifstream& archivo) {
    Insumo buffer[tam::buffer] {};
    
    int num = 0;
    while (archivo >> buffer[num]) num++;
    
    insumos = new Insumo[num] {};
    
    cantidad = num;
    for (int i = 0; i < num; i++) {
        insumos[i] = buffer[i];
    }
}

Insumo* Inventario::buscarInsumo(const char* codigoInsumo) {
    Insumo* resultado = {};
    
    for (int i = 0; i < cantidad; i++) {
        Insumo* insumo = &insumos[i];
        char* codigo = insumo->getCodigo();
        
        if (strcmp(codigoInsumo, codigo) == 0) {
            resultado = insumo;
            break;
        }
    }
    
    return resultado;
}

int Inventario::getCantidad() {
    return cantidad;
}

Inventario::~Inventario() {
    delete[] insumos;
}
