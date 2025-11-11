//
// Created by Eric Huiza on 11/7/25.
//

#ifndef SESION_DE_CLASE_22_01_ALUMNOINFO_H
#define SESION_DE_CLASE_22_01_ALUMNOINFO_H
#include "Alumno.h"


using namespace std;
class AlumnoInfo {
    unique_ptr<Alumno> alumnoPtr;
public:
    AlumnoInfo() = default;
    AlumnoInfo(const AlumnoInfo&);
    AlumnoInfo& operator=(const AlumnoInfo&);

    bool operator<(const AlumnoInfo&) const;

    friend istream& operator>>(istream& is, AlumnoInfo& alumno);
    friend ostream& operator<<(ostream&, const AlumnoInfo&);
};


#endif //SESION_DE_CLASE_22_01_ALUMNOINFO_H