/* 
 * File:   Cliente.h
 * Author: erichuiza
 *
 * Created on May 30, 2025, 11:56 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <cstring>
#include <iostream>
#include <fstream>

#include "Persona.h"

class Cliente : public Persona {
private:
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
    bool cargarDatos(ifstream&);
    void imprimir(ostream&) const;
    
    virtual ~Cliente();
};

//bool operator>>(ifstream&, Cliente&);
//ostream& operator<<(ostream&, const Cliente&);

#endif /* CLIENTE_H */

