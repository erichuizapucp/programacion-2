/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on May 30, 2025, 10:54 AM
 */

#include <cstdlib>

#include "ClaseA.h"
#include "ClaseB.h"
#include "ClaseC.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    ClaseA* p1 = new ClaseB;
    p1->imprimir();
    
    ClaseA* p2 = new ClaseC;
    p2->imprimir();
    
    return 0;
}

