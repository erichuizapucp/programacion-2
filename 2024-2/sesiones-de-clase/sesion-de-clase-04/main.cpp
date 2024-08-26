/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on August 26, 2024, 11:06 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int* f() {
    int* arr = new int[5] { 1, 2, 3, 4, 5 };
    int* p;
    p = arr;
    return p;
}


void g(int *const p) {
    *p = 7;
}

void gg(int &p) {
    p = 8;
}

/*
 * 
 */
int main(int argc, char** argv) {
    // Aquí se muestra un error de concepto al
    // retornar una dirección de memoria de una variable local
    int* a = f();
    cout << *a << endl;
    cout << *a << endl;
    cout << *a << endl;
    
    int h = 6;
    // Paso de un puntero constante.
    g(&h);
    cout << h << endl;
    
    // Paso por referencia
    gg(h);
    cout << h << endl;
    
    int* c = new int[2] { 3, 4 };
    
    delete a;
    delete[] c;
    
    int arr[5] { 1, 2, 3, 4, 5 };
    
    int* p = &arr[2];
    p[0] = 5;
    p[1] = 7;
    
    // Son equivalentes
    cout << arr[3] << endl;
    cout << *(arr + 3) << endl;
    
    // Son equivalentes
    cout << arr[0] << endl;
    cout << *arr << endl;
    
    return 0;
}

