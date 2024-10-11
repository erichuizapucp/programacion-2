/* 
 * File:   funciones.h
 * Author: erichuiza
 *
 * Created on October 7, 2024, 11:54 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>

#include "Insumo.h"
#include "Bebida.h"
#include "Menu.h"
#include "enums.h"

using namespace std;

bool operator>>(ifstream&, Insumo&);
bool operator>>(ifstream&, Bebida&);
void operator<<(ofstream&, const Menu&);
void operator<<(ofstream&, const Bebida&);
char* leeCadena(ifstream&, char=',');

#endif /* FUNCIONES_H */

