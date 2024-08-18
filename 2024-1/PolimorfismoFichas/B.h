/* 
 * File:   B.h
 * Author: erichuiza
 *
 * Created on May 30, 2024, 10:27 PM
 */

#ifndef B_H
#define B_H

#include <fstream>
#include <iomanip>
#include "Ficha.h"

using namespace std;

class B : public Ficha {
    void imprime(ofstream&);
    void mover(char, int);
};

#endif /* B_H */

