/* 
 * File:   A.h
 * Author: erichuiza
 *
 * Created on May 30, 2024, 10:27 PM
 */

#ifndef A_H
#define A_H

#include <fstream>
#include <iomanip>
#include "Ficha.h"

using namespace std;

class A : public Ficha {
    void imprime(ofstream&);
    void mover(char, int);
};

#endif /* A_H */

