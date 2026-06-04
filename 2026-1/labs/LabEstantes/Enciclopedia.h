#ifndef LABESTANTES_ENCICLOPEDIA_H
#define LABESTANTES_ENCICLOPEDIA_H

#include "Libro.h"

using namespace std;

class Enciclopedia : public Libro {
    int volumen;
public:
    Enciclopedia();
    Enciclopedia(const Enciclopedia&);
    Enciclopedia& operator=(const Enciclopedia&);

    int getVolumen() const;

    void setVolumen(int);
};

#endif
