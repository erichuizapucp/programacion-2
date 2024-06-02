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
    Cola* cola = new Cola();
    
    for (int i = 0; i < 5; i++) {
        cola->encola(&numeros[i]);
    }
    
    int* dato = (int*)cola->desencola();
    cout << *dato << endl;
    
//    int* x = new int(10);
//    Nodo* nuevoNodo = new Nodo(x);
//    cola->getFrente()->
    
    int* dato2 = (int*)cola->desencola();
    cout << *dato2 << endl;
    
    int* dato3 = (int*)cola->desencola();
    cout << *dato3 << endl;
    
    delete cola;
    
    cout << "Plantillas" << endl;
    
    Arreglo<int> arr;
    arr.insetar(0, 1);
    arr.insetar(1, 2);
    arr.insetar(2, 3);
    arr.insetar(3, 4);
    arr.insetar(4, 5);
    
    for (int i = 0; i < 5; i++) {
        cout << arr.obtener(i) << endl;
    }
    
    Arreglo<double> arrd;
    arrd.insetar(0, 1.4);
    arrd.insetar(1, 2.3);
    arrd.insetar(2, 3.6);
    arrd.insetar(3, 4.2);
    arrd.insetar(4, 5.9);
    
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << arrd.obtener(i) << endl;
    }
    
    return 0;
}

