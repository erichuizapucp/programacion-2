#ifndef PEDIDOPRIORITARIO_H
#define PEDIDOPRIORITARIO_H

#include "Pedido.h"
#include "PedidoPrioridad.h"

class PedidoPrioritario : public Pedido {
public:
    PedidoPrioritario() = default;
    PedidoPrioritario(const PedidoPrioritario& orig);
    
    PedidoPrioritario& operator=(const PedidoPrioritario&);
    PedidoPrioridad getPrioridad() const override;
    Pedido* clonar() const override;
    
    ~PedidoPrioritario() override = default;
};

#endif /* PEDIDOPRIORITARIO_H */

