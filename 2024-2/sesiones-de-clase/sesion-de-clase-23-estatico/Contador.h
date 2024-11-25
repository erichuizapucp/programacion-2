/* 
 * File:   Contador.h
 * Author: erichuiza
 *
 * Created on November 22, 2024, 3:32 PM
 */

#ifndef CONTADOR_H
#define CONTADOR_H

class Contador {
    static int cantidad;
public:
    Contador();
    Contador(const Contador& orig);
    virtual ~Contador();
    
    int getCantidad();
    
    static void incrementar();
};

#endif /* CONTADOR_H */

