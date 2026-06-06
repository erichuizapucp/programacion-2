#ifndef PERSONA_H
#define PERSONA_H

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Registro.h"

using namespace std;

class Persona : public Registro {
    int dni;
    char* nombre;
protected:
    istream& leer(istream&) override;
    ostream& imprimir(ostream&) const override;
public:
    Persona();
    Persona(int, const char*);
    Persona(const Persona& orig);
    
    int getDni() const;
    void setDni(int);
    char* getNombre() const;
    void setNombre(const char*);
    
    Persona& operator=(const Persona&);
    
    virtual ~Persona();
};



#endif /* PERSONA_H */