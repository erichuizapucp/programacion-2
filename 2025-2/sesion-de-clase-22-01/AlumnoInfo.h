//
// Created by Eric Huiza on 11/7/25.
//

#ifndef SESION_DE_CLASE_22_01_ALUMNOINFO_H
#define SESION_DE_CLASE_22_01_ALUMNOINFO_H
#include "Alumno.h"


using namespace std;
class AlumnoInfo {
    Alumno* alumnoPtr;
public:
    AlumnoInfo() : alumnoPtr(nullptr) {};
    AlumnoInfo(const AlumnoInfo&);
    AlumnoInfo& operator=(const AlumnoInfo&);

    friend istream& operator>>(istream& is, AlumnoInfo& alumno);
    friend ostream& operator<<(ostream&, const AlumnoInfo&);

    ~AlumnoInfo();
};


#endif //SESION_DE_CLASE_22_01_ALUMNOINFO_H