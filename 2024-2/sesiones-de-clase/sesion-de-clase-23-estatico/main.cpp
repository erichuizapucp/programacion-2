/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on November 22, 2024, 3:32 PM
 */

#include <cstdlib>

#include "Contador.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Contador c1;
    Contador c2;
    
    Contador::incrementar();

    cout << c1.getCantidad() << endl;
    
    Contador::incrementar();
    
    cout << c1.getCantidad() << endl;
    cout << c2.getCantidad() << endl;
    
    return 0;
}

