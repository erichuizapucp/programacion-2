//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_REGISTRO_H
#define EJERCICIO02_REGISTRO_H

#include <fstream>
#include <cstring>

using namespace std;

class Registro {
public:
    ifstream& leer(ifstream&);
    ofstream& imprimir(ofstream&) const;
protected:
    char* leerCadena(ifstream&, char = ',');
    void setCadena(char*&, const char*);
};


#endif //EJERCICIO02_REGISTRO_H

