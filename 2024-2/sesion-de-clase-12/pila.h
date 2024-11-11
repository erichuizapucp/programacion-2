/* 
 * File:   pila.h
 * Author: erichuiza
 *
 * Created on September 27, 2024, 3:24 PM
 */

#ifndef PILA_H
#define PILA_H

class Pila {
private:
    int* datos;
    int cima;
public:
    void apilar(int dato);
    int desapilar();
};

struct StPila {
private:
    int* datos;
    int cima;
public:
    void apilar(int dato);
    int desapilar();
};

#endif /* PILA_H */

