#ifndef LABESTANTES_NOVELA_H
#define LABESTANTES_NOVELA_H

#include "Libro.h"

using namespace std;

class Novela : public Libro {
    char* tipo;
public:
    Novela();
    Novela(const Novela&);
    Novela& operator=(const Novela&);

    char* getTipo() const;

    void setTipo(const char*);

    ~Novela();
};

#endif
