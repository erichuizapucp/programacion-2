#ifndef CLIENTE_H
#define CLIENTE_H

#include <cstring>
#include <iostream>
#include <fstream>

#include "Persona.h"

class Cliente : public Persona {
    char* telefono;
    char* correo;
public:
    Cliente();
    Cliente(int, const char*, const char*, const char*);
    Cliente(const Cliente& orig);
    
    char* getCorreo() const;
    void setCorreo(const char*);
    char* getTelefono() const;
    void setTelefono(const char*);
    
    Cliente& operator=(const Cliente&);
    istream& leer(istream&) override;
    ostream& imprimir(ostream&) const override;
    
    ~Cliente() override;
};

#endif /* CLIENTE_H */

