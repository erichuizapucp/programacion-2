//
// Created by Eric Huiza on 10/6/25.
//

#ifndef SESION_DE_CLASE_15_PUBLICACION_H
#define SESION_DE_CLASE_15_PUBLICACION_H

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Publicacion {
    int id;
    int fecha;
    char* cuenta;
    char** menciones;
    char* texto;
public:
    Publicacion();
    Publicacion(const Publicacion&);

    int getId() const;
    void setId(int id);
    int getFecha() const;
    void setFecha(int fecha);
    char* getCuenta() const;
    void setCuenta(char *cuenta);
    char** getMenciones() const;
    void setMenciones(char** menciones);
    char* getTexto() const;
    void setTexto(char *texto);

    Publicacion& operator=(const Publicacion&);

    char* leerCadena(istream&, char=',');
    void imprimirFecha(ostream&) const;

    bool leerMencion(istream&, char*&);
    void cargarMenciones(istream&, char**&);

    ~Publicacion();
};

istream& operator>>(istream&, Publicacion&);
ostream& operator<<(ostream&, const Publicacion&);


#endif //SESION_DE_CLASE_15_PUBLICACION_H