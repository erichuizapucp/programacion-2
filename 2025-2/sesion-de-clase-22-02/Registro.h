//
// Created by Eric Huiza on 11/7/25.
//

#ifndef SESION_DE_CLASE_22_01_REGISTRO_H
#define SESION_DE_CLASE_22_01_REGISTRO_H

#include <iostream>

using namespace std;

class Registro {
protected:
    virtual istream& leer(istream&) = 0;
    virtual ostream& imprimir(ostream&) const = 0;
public:
    friend istream& operator>>(istream&, Registro&);
    friend ostream& operator<<(ostream&, const Registro&);
};


#endif //SESION_DE_CLASE_22_01_REGISTRO_H