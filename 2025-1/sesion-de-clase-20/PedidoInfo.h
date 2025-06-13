/* 
 * File:   PedidoInfo.h
 * Author: erichuiza
 *
 * Created on June 9, 2025, 11:54 AM
 */

#ifndef PEDIDOINFO_H
#define PEDIDOINFO_H

#include "Pedido.h"

class PedidoInfo {
private:
    Pedido* pedido;
public:
    PedidoInfo();
    PedidoInfo(Pedido* pedido);
    PedidoInfo(const PedidoInfo& orig);
    
    Pedido* getPedido() const;
    void setPedido(Pedido* pedido);
    
    PedidoInfo& operator=(const PedidoInfo&);
    bool operator<(const PedidoInfo&) const;
    
    virtual ~PedidoInfo();
};

#endif /* PEDIDOINFO_H */

