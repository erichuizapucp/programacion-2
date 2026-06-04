#ifndef LABESTANTES_BIBLIOTECA_H
#define LABESTANTES_BIBLIOTECA_H

#include "EstanteVertical.h"
#include "EstanteHorizontal.h"
#include <iostream>
#include <fstream>

using namespace std;

class Biblioteca {
    EstanteVertical estantesVerticales[40];
    int cantidadEstantesVerticales;
    EstanteHorizontal estantesHorizontales[40];
    int cantidadEstantesHorizontales;
    Enciclopedia enciclopedias[200];
    int cantidadTotalEnciclopedias;
    Novela novelas[200];
    int cantidadTotalNovelas;

    void cargarNovela(ifstream&);
    void cargarEnciclopedia(ifstream&);
    void cargarEstanteHorizontal(ifstream&);
    void cargarEstanteVertical(ifstream&);
    bool colocarNovela(Novela&);
    bool colocarEnciclopedia(Enciclopedia&);
    void imprimirDetalleNovelas(EstanteHorizontal&);
    void imprimirDetalleEnciclopedias(EstanteVertical&);
public:
    Biblioteca();
    void cargarLibros();
    void cargarEstantes();
    void posicionarLibros();
    void mostrarDatos();
};

#endif
