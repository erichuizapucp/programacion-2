/* 
 * File:   AlumnoIntercambio.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 3:19 PM
 */

#ifndef ALUMNOINTERCAMBIO_H
#define ALUMNOINTERCAMBIO_H

#include "Alumno.h"

class AlumnoIntercambio : public Alumno {
private:
    string paisOrigen;
    string universidadOrigen;
    int duracion;
protected:
    void cargar(ifstream&);
    void imprimir(ofstream&) const;
public:
    AlumnoIntercambio();
    AlumnoIntercambio(const AlumnoIntercambio& orig);
    
    Alumno* clonar();
    virtual ~AlumnoIntercambio();
    
    void operator=(const AlumnoIntercambio&);
};

#endif /* ALUMNOINTERCAMBIO_H */

