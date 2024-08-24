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
    char* nombre;
    double subTotal; // total comprado antes de impuestos
    double subTotalDescuento;
    double igv;
    double total; // total comprado después de impuestos
    double descuento;
};

struct Empleado {
    int dni;
    char* nombre;
    double sueldoBruto; // sueldo antes de impuestos
    double impuestos; 
    double sueldoNeto; // sueldo luego de impuestos
};

#endif /* ESTRUCTURAS_H */

