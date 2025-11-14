#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>

using namespace std;

class Registro {
protected: 
    char* leerCadena(istream&, char=',');
    virtual istream& leer(istream&) = 0;
    virtual ostream& imprimir(ostream&) const = 0;

    void setCadena(char*&, const char*);
public:
    friend istream& operator>>(istream&, Registro&);
    friend ostream& operator<<(ostream&, const Registro&);
};

#endif /* REGISTRO_H */

