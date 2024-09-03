/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on August 25, 2024, 9:21 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "restaurante.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Mesa* mesas;
    Mesero* meseros;
    cargarDatos("mesas.csv", "meseros.csv", mesas, meseros);
    
    ListaReservas listaReservas;
    procesarReservas("reservas.csv", mesas, meseros, listaReservas);
    
    generarReporte("reporte.txt", listaReservas);
   
//    liberarMemoria(mesas, meseros, reservas);
    
    return 0;
}

