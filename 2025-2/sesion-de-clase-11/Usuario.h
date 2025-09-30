//
// Created by Eric Huiza on 9/22/25.
//

#ifndef SESION_DE_CLASE_11_USUARIO_H
#define SESION_DE_CLASE_11_USUARIO_H

#include <cstring>
#include <iostream>

using namespace std;

class  Usuario {
    char* cuenta;
    char* nombre;
    char* correo;
    char* facultad;
    int edad;
    int fechaRegistro;
public:
    Usuario();
    Usuario& operator=(const Usuario&);

    char* getCuenta() const;
    void setCuenta(const char*);
    char* getNombre() const;
    void setNombre(const char*);
    char* getCorreo() const;
    void setCorreo(const char*);
    char* getFacultad() const;
    void setFacultad(const char*);
    int getEdad() const;
    void setEdad(int edad);
    int getFechaRegistro() const;
    void setFechaRegistro(int);
    void cargarDatos();

    char* leerCadena(istream&);

    ~Usuario();
};

istream& operator>>(istream&, Usuario&);
ostream& operator<<(ostream&, const Usuario&);

#endif //SESION_DE_CLASE_11_USUARIO_H