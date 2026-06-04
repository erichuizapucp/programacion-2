#ifndef LABESTANTES_ESTANTEHORIZONTAL_H
#define LABESTANTES_ESTANTEHORIZONTAL_H

#include "Estante.h"
#include "Novela.h"

using namespace std;

class EstanteHorizontal : public Estante {
    Novela novelas[100];
    int cantidadNovelas;
public:
    EstanteHorizontal();
    Novela* getNovelas();
    int getCantidadNovelas() const;
    void setCantidadNovelas(int);
    bool insertarNovela(const Novela&);
};

#endif
