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
//    int arr[3][3] { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
//    
//    int* p1 = *arr; // puntero al primer arreglo
//    int* p2 = *(arr + 1); // puntero al segundo arreglo
//    int* p3 = *(arr + 2); // puntero al tercer arreglo
//    
//    cout << *(p2 + 2) << endl; // imprime 6, el tercer valor del segundo arreglo
//
//    int** arr1 = new int*[3];
//    arr1[0] = new int[5] { 1, 2, 3, 4, 5 };
//    arr1[1] = new int[2] { 6, 7 };
//    arr1[2] = new int[3] { 8, 9, 10 };
//    
//    cout << *(*(arr1 + 2) + 2) << endl; // imprime 10, el tercer elemento del tercer arreglo
    
    int** mesas;
    int** reservas;
    char** nombres;
    
    cargarMesas("mesas.csv", mesas);
    cargarReservas("reservas.csv", reservas, nombres);
    
    mostrarMesas("reporteMesas.txt", (const int**)mesas);
    mostrarReservas("reporteReservas.txt", (const int**)reservas, (const char**)nombres);
    
    //TODO: liberar memoria para punteros unidimensionales
    
    delete[] mesas;
    delete[] reservas;
    delete[] nombres;
    
    return 0;
}
