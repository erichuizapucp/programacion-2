/* 
 * File:   estructuras.h
 * Author: erichuiza
 *
 * Created on August 25, 2024, 9:38 AM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct Mesero {
    int dni;
    char* nombre;
    double sueldoBruto;
    int experiencia;
    bool asignadoTurno1 = false;
    bool asignadoTurno2 = false;
};

struct Mesa {
    char tipo;
    char* codigo;
    char* ubicacion;
    int capacidad;
    char* articulos;
    bool reservadaTurno1 = false;
    bool reservadaTurno2 = false;
};

struct Reserva {
    int dni;
    char* nombre;
    char ubicacion;
    int turno;
    int noPersonas;
    char* articulos;
    Mesa* mesa;
    Mesero* mesero;
};

struct NodoReserva {
    NodoReserva* siguiente;
    const Reserva* datos;
};

struct ListaReservas {
    int cantidad;
    NodoReserva* cabeza;
    NodoReserva* cola;
};

#endif /* ESTRUCTURAS_H */

