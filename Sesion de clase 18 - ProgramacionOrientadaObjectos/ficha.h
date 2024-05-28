/* 
 * File:   ficha.h
 * Author: erichuiza
 *
 * Created on May 27, 2024, 9:41 AM
 */

#ifndef FICHA_H
#define FICHA_H

#include <iostream>

using namespace std;

class Ficha {
private:
    int codigo;
    int fila;
    int columna;
protected:
    int getCodigo();
    int getFila();
    int getColumna();
    
    void setFila(int fila);
    void setColumna(int columna);
public:
    Ficha(int);
    
    virtual void mover(int, int) = 0;
    virtual void imprimir() = 0;
    
    virtual ~Ficha();
};

#endif /* FICHA_H */

