/* 
 * File:   AlumnoRegular.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 3:18 PM
 */

#ifndef ALUMNOREGULAR_H
#define ALUMNOREGULAR_H

#include "Alumno.h"


class AlumnoRegular : public Alumno {
private:
    int annoIngreso;
protected:
    void cargar(ifstream&);
    void imprimir(ofstream&) const;
public:
    AlumnoRegular();
    AlumnoRegular(const AlumnoRegular& orig);
    
    void operator=(const AlumnoRegular& orig);
    Alumno* clonar();
    
    virtual ~AlumnoRegular();
};

#endif /* ALUMNOREGULAR_H */

