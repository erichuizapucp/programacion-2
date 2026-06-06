//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_REGISTRO_H
#define EJERCICIO02_REGISTRO_H

#include <fstream>
#include <cstring>

using namespace std;

class Registro {
protected:
    char* leerCadena(ifstream&, char = ',');
    void setCadena(char*&, const char*);

    virtual ifstream& leer(ifstream&) = 0;
    virtual ofstream& imprimir(ofstream&) const = 0;
public:
    friend ifstream& operator>>(ifstream&, Registro&);
    friend ofstream& operator<<(ofstream&, const Registro&);
};

#endif //EJERCICIO02_REGISTRO_H

