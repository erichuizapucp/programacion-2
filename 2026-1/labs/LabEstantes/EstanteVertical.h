#ifndef LABESTANTES_ESTANTEVERTICAL_H
#define LABESTANTES_ESTANTEVERTICAL_H

#include "Estante.h"
#include "Enciclopedia.h"

using namespace std;

class EstanteVertical : public Estante {
    Enciclopedia enciclopedias[100];
    int cantidadEnciclopedias;
public:
    EstanteVertical();
    Enciclopedia* getEnciclopedias();
    int getCantidadEnciclopedias() const;
    void setCantidadEnciclopedias(int);
    bool insertarEnciclopedia(const Enciclopedia&);
};

#endif
