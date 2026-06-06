#ifndef PEDIDOREGULAR_H
#define PEDIDOREGULAR_H

#include "Pedido.h"
#include "PedidoPrioridad.h"

class PedidoRegular : public Pedido {
public:
    PedidoRegular() = default;
    PedidoRegular(const PedidoRegular& orig);
    
    PedidoRegular& operator=(const PedidoRegular&);
    PedidoPrioridad getPrioridad() const override;
    Pedido* clonar() const override;
    
    ~PedidoRegular() override = default;
};

#endif /* PEDIDOREGULAR_H */

