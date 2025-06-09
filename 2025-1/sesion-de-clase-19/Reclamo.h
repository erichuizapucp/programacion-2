/* 
 * File:   Reclamo.h
 * Author: erichuiza
 *
 * Created on June 6, 2025, 5:39 PM
 */

#ifndef RECLAMO_H
#define RECLAMO_H

#include "Registro.h"


class Reclamo : public Registro {
public:
    Reclamo() = default;
//    Reclamo(const Reclamo& orig);
    virtual ~Reclamo() = default;
};

#endif /* RECLAMO_H */

