/* 
 * File:   estructuras.h
 * Author: erichuiza
 *
 * Created on August 21, 2024, 3:42 PM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct Cliente {
    int dni;
    double subTotal; // total comprado antes de impuestos
    double subTotalDescuento;
    double igv;
    double total; // total comprado después de impuestos
    double descuento;
};

struct Datos {
    const int* dnis;
    const double* subTotales;
};

#endif /* ESTRUCTURAS_H */

