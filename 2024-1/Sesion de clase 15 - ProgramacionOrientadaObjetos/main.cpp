/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on May 6, 2024, 3:34 PM
 */

#include <cstdlib>

#include "Vector2D.h"
#include "Circulo.h"
#include "Cilindro.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Vector2D vec1(2, 4);
    Vector2D vec2(1, 1);
    Vector2D vec3 = vec1 + vec2;
    
    cout << vec3;
    
//    Circulo c1(4);
//    cout << c1.calcularArea();
//    
//    Cilindro cc1(4, 5);
//    cout << cc1.calcularArea();
    
    return 0;
}

