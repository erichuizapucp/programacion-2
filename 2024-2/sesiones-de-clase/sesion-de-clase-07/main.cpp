/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on September 5, 2024, 10:45 PM
 */

#include <cstdlib>

#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int** mesas;
    int** reservas;
    char** nombres;
    double*** propinas;
    
    cargarMesasExactas("mesas.csv", mesas);
    cargarReservasIncremento("reservas.csv", reservas, nombres);
    cargarPropinasExactas("propinas.csv", propinas);
    
    mostrarMesas("reporteMesas.txt", (const int**)mesas);
    mostrarReservas("reporteReservas.txt", (const int**)reservas, (const char**)nombres);
    mostrarPropinas("reportePropinas.txt", (const double***)propinas);
    
    //TODO: liberar memoria para punteros unidimensionales
    
    delete[] mesas;
    delete[] reservas;
    delete[] nombres;
    
    // TODO: liberar memoria para punteros bi-dimensionales
    // TODO: libnerar memoria para punteros unidimensionales
    delete[] propinas;
    
    return 0;
}
