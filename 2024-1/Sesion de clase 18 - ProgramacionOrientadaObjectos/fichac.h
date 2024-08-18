/* 
 * File:   fichac.h
 * Author: erichuiza
 *
 * Created on May 27, 2024, 10:17 AM
 */

#ifndef FICHAC_H
#define FICHAC_H

#include "ficha.h"

using namespace std;

class FichaC : public Ficha {
public:
    FichaC(int);
    
    void mover(int, int) override;
    void imprimir() override;
    
    ~FichaC() override;
};

#endif /* FICHAC_H */

