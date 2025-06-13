/* 
 * File:   OrdenarMeseroPorNombre.h
 * Author: erichuiza
 *
 * Created on June 13, 2025, 5:31 PM
 */

#ifndef COMPARADORES_H
#define COMPARADORES_H

#include "Mesero.h"

class OrdenaMeseroPorNombre {
public:
    bool operator()(const Mesero&, const Mesero&) const;
};

class OrdenarMeseroPorExperiencia {
public:
    bool operator()(const Mesero&, const Mesero&) const;
};

#endif /* COMPARADORES_H */

