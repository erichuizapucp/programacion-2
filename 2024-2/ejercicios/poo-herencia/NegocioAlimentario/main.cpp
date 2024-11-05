/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on October 17, 2024, 11:46 AM
 */

#include <cstdlib>
#include "Cafeteria.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Cafeteria cafeteria;
    cafeteria.cargarInventario("inventario.csv");
    cafeteria.cargarMenu("menu.csv");
//    cafeteria.actualizarMenu("ingredientes.csv");
    cafeteria.reporteMenu("menu.txt");
    
    return 0;
}

