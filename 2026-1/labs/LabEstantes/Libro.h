#ifndef LABESTANTES_LIBRO_H
#define LABESTANTES_LIBRO_H

#include <iostream>

using namespace std;

class Libro {
    char* codigo;
    char* nombre;
    int ancho;
    int alto;
    double peso;
    bool colocado;
public:
    Libro();
    Libro(const Libro&);
    Libro& operator=(const Libro&);

    char* getCodigo() const;
    char* getNombre() const;
    int getAncho() const;
    int getAlto() const;
    double getPeso() const;
    bool getColocado() const;

    void setCodigo(const char*);
    void setNombre(const char*);
    void setAncho(int);
    void setAlto(int);
    void setPeso(double);
    void setColocado(bool);

    ~Libro();
};

#endif
