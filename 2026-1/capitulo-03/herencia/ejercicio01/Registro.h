//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO01_REGISTRO_H
#define EJERCICIO01_REGISTRO_H

#include <iostream>
#include <fstream>

using namespace std;

class Registro {
public:
    Registro();

    void leer(ifstream&);
    void imprimir(ofstream&);

    ~Registro();
};


#endif //EJERCICIO01_REGISTRO_H
