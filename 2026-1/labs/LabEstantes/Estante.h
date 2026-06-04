#ifndef LABESTANTES_ESTANTE_H
#define LABESTANTES_ESTANTE_H

#include "Espacio.h"
#include <iostream>

using namespace std;

class Estante {
    char* codigo;
    int anchura;
    int altura;
    Espacio* espacios;
    double pesoSoportado;
    double pesoActual;
    int totalCeldas() const;
    int indiceDesdeXY(int, int) const;
public:
    Estante();
    Estante(const Estante&);
    Estante& operator=(const Estante&);

    char* getCodigo() const;
    int getAnchura() const;
    int getAltura() const;
    Espacio* getEspacios() const;
    double getPesoSoportado() const;
    double getPesoActual() const;

    void setCodigo(const char*);
    void setAnchura(int);
    void setAltura(int);
    void setPesoSoportado(double);
    void setPesoActual(double);

    void crearMatriz();
    int obtenerEspaciosRestantes() const;
    bool puedeInsertarRectangulo(int, int, int, int) const;
    bool encontrarPosicion(int, int, int&, int&) const;
    void marcarRectangulo(int, int, int, int, char = '*');
    void mostrarMatriz(ostream&) const;

    ~Estante();
};

#endif
