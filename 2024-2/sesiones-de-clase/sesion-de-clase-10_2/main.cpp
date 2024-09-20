/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on September 13, 2024, 1:33 PM
 */

#include <cstdlib>

#include "funciones.h"

using namespace std;

int comparar(const void* a, const void* b) {
    int* pa = (int*)a;
    int* pb = (int*)b;
    
    return *pa - *pb;
}

int main(int argc, char** argv) {
    void* meseros;

    cargarDatos("meseros.csv", meseros);
    mostrarDatos(meseros);

    void* mesero;
    if (buscar(79832456, meseros, mesero)) {
        cout << endl << "Se encontró al mesero" << endl;
        cout << (const void**)mesero;
    }
    
    liberarMemoria(meseros);
    
    cout << endl;
    
    int* arr = new int[5] { 3, 4, 8, 9, 7 };
    qsort(arr, 5, sizeof(int), comparar);
    
    int llave = 8;
    int* res = (int*)bsearch(&llave, arr, 5, sizeof(int), comparar);
    cout << *res;
    
    delete[] arr;
    
    return 0;
}

