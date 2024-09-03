/* 
 * File:   restaurante.h
 * Author: erichuiza
 *
 * Created on August 25, 2024, 9:39 AM
 */

#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "archivos.h"
#include "estructuras.h"
#include "enums.h"

using namespace std;

void cargarDatos(const char*, const char*, Mesa*&, Mesero*&);
void procesarReservas(const char*, Mesa*&, Mesero*&, ListaReservas&);
void generarReporte(const char*, ListaReservas&);

bool operator>>(ifstream&, Mesa*&);
bool operator>>(ifstream&, Mesero*&);
bool operator>>(ifstream&, Reserva*&);

void inicializarListaReservas(ListaReservas&);
void asignarMesa(Reserva*&, Mesa*&);
void asignarMeseros(Reserva*&, Mesero*&);
void operator+=(ListaReservas&, const Reserva*);
void insertarSiguienteReserva(ListaReservas&, NodoReserva*, const Reserva*);

ofstream& operator<<(ofstream&, const Reserva*);
ofstream& operator<<(ofstream&, const ListaReservas&);

void llenarReserva(Reserva*&, int, char*, char, int, int, char*);
char* obtenerCadena(ifstream&, char=',');
char* obtenerCadena(const char*);
void liberarMemoria(Mesa*&, Mesero*&, Reserva*&);

#endif /* RESTAURANTE_H */

