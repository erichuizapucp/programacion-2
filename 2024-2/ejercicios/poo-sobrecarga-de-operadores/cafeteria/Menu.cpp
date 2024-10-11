/* 
 * File:   Menu.cpp
 * Author: erichuiza
 * 
 * Created on October 7, 2024, 10:53 AM
 */

#include "Menu.h"
#include "funciones.h"
#include "Inventario.h"

Menu::Menu() {
}

Menu::Menu(const Menu& orig) {
}

Bebida* Menu::getBebidas() const {
    return bebidas;
}

int Menu::getCantidad() const {
    return cantidad;
}

void Menu::cargarBebidas(ifstream& archivo) {
    Bebida buffer[tam::buffer] {};
    int num = 0;
    while (archivo >> buffer[num]) num++;
    
    bebidas = new Bebida[num] {};
    cantidad = num;
    for (int i = 0; i < num; i++) {
        bebidas[i] = buffer[i];
    }
}

Bebida* Menu::buscarBebida(const char* codigoBebida) {
    Bebida* resultado = {};
    
    for (int i = 0; i < cantidad; i++) {
        Bebida* bebida = &bebidas[i];
        char* codigo = bebida->getCodigo();
        
        if (strcmp(codigoBebida, codigo) == 0) {
            resultado = bebida;
            break;
        }
    }
    
    return resultado;
}

void Menu::verificar() {
    for (int i = 0; i < cantidad; i++) {
        Bebida* bebida = &bebidas[i];
        bebida->verificarDisponibilidad();
    }
}

Menu::~Menu() {
    delete[] bebidas;
}
