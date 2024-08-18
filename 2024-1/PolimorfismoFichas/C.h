/* 
 * File:   C.h
 * Author: erichuiza
 *
 * Created on May 30, 2024, 10:27 PM
 */

#ifndef C_H
#define C_H

#include <fstream>
#include <iomanip>
#include "Ficha.h"

using namespace std;

class C : public Ficha {
    void imprime(ofstream&);
    void mover(char, int);
};

#endif /* C_H */

