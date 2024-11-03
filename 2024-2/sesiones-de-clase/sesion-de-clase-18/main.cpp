/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on May 27, 2024, 9:36 AM
 */

#include <cstdlib>

#include "cola.h"
#include "arreglo.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int* numeros = new int[5] { 4, 5, 2, 8, 6 };
    Cola<int>* cola = new Cola<int>();
    
    for (int i = 0; i < 5; i++) {
        cola->encola(numeros[i]);
    }
    
    int dato;
    if (cola->desencola(dato)) {
        cout << dato << endl;
    }
    
    int dato2;
    if (cola->desencola(dato2)) {
        cout << dato2 << endl;
    }
    
    
    int dato3;
    if (cola->desencola(dato3)) {
        cout << dato3 << endl;
    }
    
    delete cola;
    
    cout << "Plantillas" << endl;
    
    Arreglo<int> arr;
    arr.insertar(0, 1);
    arr.insertar(1, 2);
    arr.insertar(2, 3);
    arr.insertar(3, 4);
    arr.insertar(4, 5);
    
    for (int i = 0; i < 5; i++) {
        cout << arr.obtener(i) << endl;
    }
    
    Arreglo<double> arrd;
    arrd.insertar(0, 1.4);
    arrd.insertar(1, 2.3);
    arrd.insertar(2, 3.6);
    arrd.insertar(3, 4.2);
    arrd.insertar(4, 5.9);
    
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << arrd.obtener(i) << endl;
    }
    
    Arreglo<const char*> arrc;
    arrc.insertar(0, "1");
    arrc.insertar(1, "2");
    arrc.insertar(2, "3");
    arrc.insertar(3, "4");
    arrc.insertar(4, "5");
    
    return 0;
}

