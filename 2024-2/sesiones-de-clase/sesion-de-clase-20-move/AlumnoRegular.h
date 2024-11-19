/* 
 * File:   AlumnoRegular.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 3:18 PM
 */

#ifndef ALUMNOREGULAR_H
#define ALUMNOREGULAR_H

#include "Alumno.h"
#include <utility>


class AlumnoRegular : public Alumno {
private:
    int annoIngreso;
protected:
    void cargar(ifstream&);
    void imprimir(ofstream&) const;
public:
    AlumnoRegular();
    AlumnoRegular(const AlumnoRegular& orig);
    AlumnoRegular(AlumnoRegular&& orig);
    
    AlumnoRegular& operator=(const AlumnoRegular& orig);
    AlumnoRegular& operator=(AlumnoRegular&&);
    Alumno* clonar();
    
    virtual ~AlumnoRegular();
};

#endif /* ALUMNOREGULAR_H */

