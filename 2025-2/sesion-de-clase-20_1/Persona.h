//
// Created by Eric Huiza on 10/31/25.
//

#ifndef SESION_DE_CLASE_20_1_PERSONA_H
#define SESION_DE_CLASE_20_1_PERSONA_H


#include <iostream>

using namespace std;

class Persona {
    char* nombre;
    int dni;
public:
    inline Persona() : nombre(nullptr), dni(0) {};
    Persona(char*, int);
    Persona(const Persona&);

    void setDni(int);
    void setNombre(char*);

    Persona& operator=(const Persona&);
    friend ostream& operator<<(ostream&, const Persona&);

    friend class MatriculaAlumno;
};

#endif //SESION_DE_CLASE_20_1_PERSONA_H