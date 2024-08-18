/* 
 * File:   fichab.h
 * Author: erichuiza
 *
 * Created on May 27, 2024, 10:17 AM
 */

#ifndef FICHAB_H
#define FICHAB_H

#include "ficha.h"

using namespace std;

class FichaB : public Ficha {
public:
    FichaB(int);
    
    void mover(int, int) override;
    void imprimir() override;
    
    ~FichaB() override;
};

#endif /* FICHAB_H */

