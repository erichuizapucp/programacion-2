//
// Created by Eric Huiza on 8/27/25.
//

#ifndef LAB01_2025_1_FUNCIONES_H
#define LAB01_2025_1_FUNCIONES_H

#include "estructuras.h"
#include <cstring>
#include <iosfwd>
#include <iostream>
#include <fstream>

using namespace std;

void operator!(CadenaDeCaracteres&);
void operator<=(CadenaDeCaracteres&, const char*);
void operator<=(CadenaDeCaracteres&, int);
void operator<=(CadenaDeCaracteres&, const CadenaDeCaracteres&);
bool operator+=(CadenaDeCaracteres&, const char*);
bool operator+=(CadenaDeCaracteres&, const CadenaDeCaracteres&);

bool operator==(CadenaDeCaracteres&, const char*);
bool operator==(CadenaDeCaracteres&, const CadenaDeCaracteres&);

bool operator<(CadenaDeCaracteres&, const char*);
bool operator<(CadenaDeCaracteres&, const CadenaDeCaracteres&);

bool operator>(CadenaDeCaracteres&, const char*);
bool operator>(CadenaDeCaracteres&, const CadenaDeCaracteres&);

bool operator>>(ifstream&, CadenaDeCaracteres&);

void operator&&(CadenaDeCaracteres&, CadenaDeCaracteres&);

ostream& operator<<(ostream&, const CadenaDeCaracteres&);

#endif //LAB01_2025_1_FUNCIONES_H