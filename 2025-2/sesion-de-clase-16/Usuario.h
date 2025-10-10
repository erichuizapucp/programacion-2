//
// Created by Eric Huiza on 9/26/25.
//

#ifndef SESION_DE_CLASE_12_USUARIO_H
#define SESION_DE_CLASE_12_USUARIO_H

#include <fstream>
#include <iostream>
#include <iomanip>

#include "Publicacion.h"
#include "Registro.h"

using namespace std;

class Usuario : public Registro {
    char* cuenta;
    char* nombre;
    char* correo;
    char* facultad;
    int fechaRegistro;
    int edad;
    Publicacion* publicaciones;
    int cantPublicaciones;
    int capacidad;

    void incrementar();
public:
    Usuario();
    Usuario(const Usuario&);
    Usuario(char*, char*, char*, char*);
    Usuario(int, int);
    Usuario(char*, char*, char*, char*, int, int);

    char* getCuenta() const;
    void setCuenta(char*);
    char* getNombre() const;
    void setNombre(char* nombre);
    char* getCorreo() const;
    void setCorreo(char* correo);
    char* getFacultad() const;
    void setFacultad(char* facultad);
    int getFechaRegistro() const;
    void setFechaRegistro(int fechaRegistro);
    int getEdad() const;
    void setEdad(int edad);
    Publicacion* getPublicaciones() const;
    int getCantPublicaciones() const;
    int getCapacidad() const;

    void imprimirFecha(ostream&) const;

    istream& leer(istream&);
    ostream& imprimir(ostream&) const;

    Usuario& operator=(const Usuario&);
    Usuario& operator+=(const Publicacion&);
    Publicacion& operator[](int) const;
    bool operator==(const Usuario&) const;
    bool operator<(const Usuario&) const;
    bool operator>(const Usuario&) const;
    bool operator<=(const Usuario&) const;
    bool operator>=(const Usuario&) const;

    operator int() const;
    operator char*() const;

    ~Usuario();
};

istream& operator>>(istream&, Usuario&);
ostream& operator<<(ostream&, const Usuario&);



#endif //SESION_DE_CLASE_12_USUARIO_H