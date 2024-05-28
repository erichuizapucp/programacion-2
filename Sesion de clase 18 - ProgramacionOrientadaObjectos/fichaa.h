/* 
 * File:   fichaa.h
 * Author: erichuiza
 *
 * Created on May 27, 2024, 10:17 AM
 */

#ifndef FICHAA_H
#define FICHAA_H

#include "ficha.h"

using namespace std;

class FichaA : public Ficha {
public:
    FichaA(int);
    
    void mover(int, int) override;
    void imprimir() override;
    
    ~FichaA() override;
};

#endif /* FICHAA_H */

