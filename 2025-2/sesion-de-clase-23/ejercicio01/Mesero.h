#ifndef MESERO_H
#define MESERO_H

#include <cstring>
#include <iostream>
#include <fstream>

#include "Persona.h"

using namespace std;

class Mesero : public Persona {
    double sueldo;
    int experiencia;
public:
    Mesero();
    Mesero(int, const char*, double, int);
    Mesero(const Mesero&);
    
    double getSueldo() const;
    void setSueldo(double);
    int getExperiencia() const;
    void setExperiencia(int);
    
    Mesero& operator=(const Mesero&);
    istream& leer(istream&) override;
    ostream& imprimir(ostream&) const override;
    
    ~Mesero() override = default;
};

#endif /* MESERO_H */

