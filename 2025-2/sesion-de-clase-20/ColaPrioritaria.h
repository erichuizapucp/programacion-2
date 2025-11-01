#ifndef COLAPRIORITARIA_H
#define COLAPRIORITARIA_H

#include "Cola.h"
#include "Pedido.h"


class ColaPrioritaria : public Cola {
public:
    ColaPrioritaria() = default;
    ColaPrioritaria(const ColaPrioritaria& orig);
    
    void encolar(Pedido*) override;
    
    ~ColaPrioritaria() override = default;
};

#endif /* COLAPRIORITARIA_H */

