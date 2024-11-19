/* 
 * File:   AlumnoRegular.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 10:34 AM
 */

#ifndef ALUMNOREGULAR_H
#define ALUMNOREGULAR_H

#include "Alumno.h"
#include <fstream>

using namespace std;

class AlumnoRegular : public Alumno {
private:
    int annoIngreso;
protected:
    virtual void cargar(ifstream&);
    virtual void imprimir(ofstream&) const;
public:
    AlumnoRegular();
    AlumnoRegular(const AlumnoRegular& orig);
    virtual ~AlumnoRegular();

    Alumno* clonar();
    char getTipo() const;
    AlumnoRegular& operator=(const AlumnoRegular&);
};

#endif /* ALUMNOREGULAR_H */

