/* 
 * File:   ColaPrioritaria.h
 * Author: erichuiza
 *
 * Created on June 4, 2025, 4:59 PM
 */

#ifndef COLAPRIORITARIA_H
#define COLAPRIORITARIA_H

#include "Cola.h"
#include "Pedido.h"


class ColaPrioritaria : public Cola {
public:
    ColaPrioritaria() = default;
    ColaPrioritaria(const ColaPrioritaria& orig);
    
    void encolar(Pedido*);
    
    virtual ~ColaPrioritaria() = default;
};

#endif /* COLAPRIORITARIA_H */

