/* 
 * File:   Carreta.h
 * Author: erichuiza
 *
 * Created on May 14, 2025, 7:42 PM
 */

#ifndef CARRETA_H
#define CARRETA_H

class Carreta {
private:
    int cantRuedas;
    double peso;
    int capacidad;
    int caballos;
public:
    Carreta();
    Carreta(const Carreta& orig);
    virtual ~Carreta();
};

#endif /* CARRETA_H */

