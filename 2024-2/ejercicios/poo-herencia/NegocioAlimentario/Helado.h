/* 
 * File:   Helado.h
 * Author: erichuiza
 *
 * Created on October 17, 2024, 11:48 AM
 */

#ifndef HELADO_H
#define HELADO_H

class Helado : public Producto {
private: 
public:
    Helado();
    Helado(const Helado&);
    virtual ~Helado();
};

#endif /* HELADO_H */

