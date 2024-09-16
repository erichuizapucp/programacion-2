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
    Mesero* meseros;

    cargarMesasExactas("mesas.csv", mesas);
    cargarReservasIncremento("reservas.csv", reservas, nombres);
    cargarPropinasIncremento("propinas.csv", propinas);
    cargarMeseros("meseros.csv", meseros, (const double***)propinas);

    mostrarMesas("reporteMesas.txt", (const int**)mesas);
    mostrarReservas("reporteReservas.txt", (const int**)reservas, (const char**)nombres);
    mostrarPropinas("reportePropinas.txt", (const double***)propinas);
    mostrarMeseros("reporteMeseros.txt", meseros);

    //TODO: liberar memoria para punteros unidimensionales
    delete[] mesas;
    delete[] reservas;
    delete[] nombres;

    // TODO: libnerar memoria para punteros unidimensionales
    // TODO: liberar memoria para punteros bi-dimensionales
    delete[] propinas;

    
    return 0;
}
