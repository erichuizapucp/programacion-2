/* 
 * File:   Contenedor.h
 * Author: erichuiza
 *
 * Created on June 3, 2024, 12:20 PM
 */

#ifndef CONTENEDOR_H
#define CONTENEDOR_H

template <typename T>
class Contenedor {
public:
    virtual void agregar(T) = 0;
    virtual int buscar(T) = 0;
    virtual T obtener(int) = 0;
    
    virtual ~Contenedor() = default;
};

#endif /* CONTENEDOR_H */

