/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on November 8, 2024, 12:13 PM
 */

#include <cstdlib>
#include <iostream>
#include "Cola.h"
#include <vector>
#include "Alumno.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Cola<int> cola {};
    Cola<double> colaD {};
    
    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);
    cola.encolar(4);
    cola.encolar(5);

    int dato;
    if (cola.desencolar(dato)) {
        cout << "Dato desencolado: " << dato << endl;
    }
    
    if (cola.desencolar(dato)) {
        cout << "Dato desencolado: " << dato << endl;
    }
    
    if (cola.desencolar(dato)) {
        cout << "Dato desencolado: " << dato << endl;
    }
    
    vector<int> v1;
    vector<double> v2;
    
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    
    v2.push_back(1.00);
    v2.push_back(2.00);
    v2.push_back(3.00);
    v2.push_back(4.00);
    v2.push_back(5.00);
    
    vector<Alumno> v3;
    Alumno a1;
    v3.push_back(a1);

    return 0;
}

