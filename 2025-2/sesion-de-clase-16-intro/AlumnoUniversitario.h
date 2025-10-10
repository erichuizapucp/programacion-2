//
// Created by Eric Huiza on 10/10/25.
//

#ifndef SESION_DE_CLASE_16_INTRO_ALUMNOUNIVERSITARIO_H
#define SESION_DE_CLASE_16_INTRO_ALUMNOUNIVERSITARIO_H
#include "Alumno.h"

using namespace std;

class AlumnoUniversitario : public Alumno {
    char* facultad;
    int ciclo;
public:
    AlumnoUniversitario();
    AlumnoUniversitario(char*, char*, int, char*, int);
    AlumnoUniversitario(const AlumnoUniversitario&);

    char* getFacultad() const;
    void setFacultad(char*);
    int getCiclo() const;
    void setCiclo(int);

    AlumnoUniversitario& operator=(const AlumnoUniversitario&);

    void imprimir();

    ~AlumnoUniversitario();
};


#endif //SESION_DE_CLASE_16_INTRO_ALUMNOUNIVERSITARIO_H