/* 
 * File:   Controlador.h
 * Author: erichuiza
 *
 * Created on November 3, 2024, 4:44 PM
 */

#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <iostream>
#include <fstream>
#include <iomanip>

#include "Menu.h"
#include "Inventario.h"
#include "Bebida.h"

using namespace std;

template<typename M, typename I>
class Negocio {
private:
    Menu<M> menu;
    Inventario<I> inventario;
public:
    Negocio();
    
    void cargarInventario(const char* nombreArchivo);
    void cargarMenu(const char* nombreArchivo);
    void actualizarMenu(const char* nombreArchivo);
    void reporteMenu(const char* nombreArchivo);
    
    friend ofstream& operator<<(ofstream&, const Menu<M>&);
    
    virtual ~Negocio();
};

template<typename M, typename I>
Negocio<M, I>::Negocio() {
    menu = {};
    inventario = {};
}

template<typename M, typename I>
void Negocio<M, I>::cargarInventario(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    inventario.cargarDatos(archivo);
}

template<typename M, typename I>
void Negocio<M, I>::cargarMenu(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    menu.cargarDatos(archivo);
}

template<typename M, typename I>
void Negocio<M, I>::actualizarMenu(const char* nombreArchivo) {
}

template<typename M, typename I>
void Negocio<M, I>::reporteMenu(const char* nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out);
    archivo << menu;
}

template<typename M>
ofstream& operator<<(ofstream& archivo, const Menu<M>& menu) {
    archivo << "============================= Menú del día ======================================" << endl;
    
    const Lista<M>& registros = menu.getDatos();
    const int cantidad = registros.getCantidad();
    
    for (int i = 0; i < cantidad; i++) {
        archivo << registros.getElementos()[i];
        archivo << "---------------------------------------------------------------------------------" << endl;
    }
    
    return archivo;
}

template<typename M, typename I>
Negocio<M, I>::~Negocio() {
}

#endif /* CONTROLADOR_H */

