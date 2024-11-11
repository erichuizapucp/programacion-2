/* 
 * File:   AlumnoIntercambio.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 10:18 AM
 */

#ifndef ALUMNOINTERCAMBIO_H
#define ALUMNOINTERCAMBIO_H

#include "Alumno.h"
#include <fstream>

using namespace std;

class AlumnoIntercambio : public Alumno {
private:
    string paisOrigen;
    string universidadOrigen;
    int duracion;
protected:
    virtual void cargar(ifstream&);
    virtual void imprimir(ofstream&) const;
public:
    AlumnoIntercambio();
    AlumnoIntercambio(const AlumnoIntercambio& orig);
    virtual ~AlumnoIntercambio();
    
    char getTipo() const;
    Alumno* clonar();
    void operator=(const AlumnoIntercambio&);
};

#endif /* ALUMNOINTERCAMBIO_H */

