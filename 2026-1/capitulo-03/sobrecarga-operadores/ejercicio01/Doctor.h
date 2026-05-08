//
// Created by Eric Huiza on 5/8/26.
//

#ifndef EJERCICIO01_DOCTOR_H
#define EJERCICIO01_DOCTOR_H
#include "enums.h"
#include <fstream>

using namespace std;

class Doctor {
    int dni;
    char* nombre;
    Especialidad especialidad;
public:
    Doctor();
    Doctor(const Doctor&);

    int getDni() const;
    char* getNombre() const;
    Especialidad getEspecialidad() const;

    void setDni(int);
    void setNombre(char*);
    void setEspecialidad(Especialidad);

    Doctor& operator=(const Doctor&);

    ~Doctor();
};

ifstream& operator>> (ifstream&, Doctor&);
ofstream& operator<< (ofstream&, const Doctor&);


#endif //EJERCICIO01_DOCTOR_H
