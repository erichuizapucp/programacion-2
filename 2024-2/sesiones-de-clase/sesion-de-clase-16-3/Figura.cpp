/* 
 * File:   Figura.cpp
 * Author: erichuiza
 * 
 * Created on October 25, 2024, 5:05 PM
 */

#include "Figura.h"

Figura::Figura() {
}

Figura::Figura(const Figura& orig) {
}

ostream& operator<<(ostream& os, const Figura& f) {
    f.imprimir(os);
    return os;
}

Figura::~Figura() {
    cout << "Destructor de Figura" << endl;
}

