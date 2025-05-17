/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on May 16, 2025, 5:37 PM
 */

#include <cstdlib>
#include "Circulo.h"
#include "Cilindro.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Circulo circulo(2.3);
    circulo.imprimirArea();
    
    Cilindro cilindro(2.3, 3.0);
    cilindro.imprimirArea();
    
    return 0;
}

