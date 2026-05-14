//
// Created by Eric Huiza on 5/13/26.
//

#ifndef EJERCICIO_CADENAS_CADENA_H
#define EJERCICIO_CADENAS_CADENA_H

#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

class Cadena {
    char* cadena;
    int longitud;
    int capacidad;
public:
    Cadena();
    Cadena(const char*);
    Cadena(int);
    Cadena(const Cadena&);

    char* getCadena() const;
    int getLongitud() const;

    void assign(const char*);
    void assign(const Cadena&);

    void append(const char*);
    void append(const Cadena&);

    void swap(Cadena&);

    int compare(const char*) const;
    int compare(const Cadena&) const;

    Cadena& operator=(const Cadena&);
    Cadena& operator=(const char*);
    Cadena operator+(const Cadena&);
    bool operator>(const Cadena&) const;
    bool operator<(const Cadena&) const;
    bool operator>=(const Cadena&) const;
    bool operator<=(const Cadena&) const;
    bool operator==(const Cadena&) const;

    ~Cadena();
};

char* leerCadena(ifstream&, char = ' ');

ifstream& operator>>(ifstream&, Cadena&);
ostream& operator<<(ostream&, const Cadena&);


#endif //EJERCICIO_CADENAS_CADENA_H
