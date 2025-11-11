//
// Created by Eric Huiza on 11/7/25.
//

#ifndef SESION_DE_CLASE_22_01_ALUMNO_H
#define SESION_DE_CLASE_22_01_ALUMNO_H

#include "Registro.h"
#include <string>

class AlumnoInfo;

using namespace std;
class Alumno : public Registro {
    int codigo {};
    string nombre;
    int edad {};
protected:
    istream& leer(istream &) override;
    ostream& imprimir(ostream &) const override;
public:
    // Alumno() = default;
    // Alumno() : codigo(0), edad(0), ciclo(0) {}

    virtual unique_ptr<Alumno> clonar() const = 0;

    friend class AlumnoInfo;

    virtual ~Alumno() = default;
};


#endif //SESION_DE_CLASE_22_01_ALUMNO_H