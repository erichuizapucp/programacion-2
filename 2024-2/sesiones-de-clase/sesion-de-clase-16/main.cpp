/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on October 21, 2024, 8:48 AM
 */

#include <cstdlib>

#include "Circulo.h"
#include "Cilindro.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Circulo c(3);
    cout << c << endl;
    
    Cilindro cc(3, 4);
    cout << cc << endl;
    
    return 0;
}

