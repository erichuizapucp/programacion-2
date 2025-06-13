/* 
 * File:   Cliente.h
 * Author: erichuiza
 *
 * Created on May 30, 2025, 11:56 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <fstream>
#include <string>

#include "Persona.h"

class Cliente : public Persona {
private:
    string telefono;
    string correo;
public:
    Cliente() = default;
    Cliente(int, const string, const string, const string);
    
    string getCorreo() const;
    void setCorreo(const string);
    string getTelefono() const;
    void setTelefono(const string);
    
    bool cargarDatos(ifstream&);
    void imprimir(ostream&) const;
    
    virtual ~Cliente() = default;
};

#endif /* CLIENTE_H */

