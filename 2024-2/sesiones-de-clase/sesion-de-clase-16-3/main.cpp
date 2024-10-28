/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on October 21, 2024, 3:38 PM
 */

#include <cstdlib>
#include "Circulo.h"
#include "Cilindro.h"
#include "Tuberia.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Circulo c(2);
    cout << c << endl;
    
    Cilindro cc(3, 5);
    cout << cc << endl;
    
    Figura* c1 = new Cilindro(6, 7);
    cout << *c1 << endl;
    delete c1;
    
    c1 = new Tuberia(5, 6, 8);
    cout << *c1 << endl;
    
    delete c1;
    
    return 0;
}

