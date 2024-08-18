/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on May 27, 2024, 9:36 AM
 */

#include <cstdlib>

#include "ficha.h"
#include "fichaa.h"
#include "fichab.h"
#include "fichac.h"
#include "cola.h"
#include "arreglo.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Ficha* f1 = new FichaA(1);
    Ficha* f2 = new FichaA(2);
    Ficha* f3 = new FichaB(3);
    Ficha* f4 = new FichaB(4);
    Ficha* f5 = new FichaC(5);
    Ficha* f6 = new FichaC(6);
    
    f1->mover(1, 1);
    f2->mover(2, 5);
    f3->mover(6, 9);
    f4->mover(1, 2);
    f5->mover(4, 6);
    f6->mover(9, 1);
    
    f1->imprimir();
    f2->imprimir();
    f3->imprimir();
    f4->imprimir();
    f5->imprimir();
    f6->imprimir();
    
    delete f1;
    delete f2;
    delete f3;
    delete f4;
    delete f5;
    delete f6;
    
    int* numeros = new int[5] { 4, 5, 2, 8, 6 };
    Cola<int>* cola = new Cola<int>();
    
    for (int i = 0; i < 5; i++) {
        cola->encola(numeros[i]);
    }
    
    //    int* x = new int(10);
    //    Nodo* nuevoNodo = new Nodo(x);
    //    cola->getFrente()->
    
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

