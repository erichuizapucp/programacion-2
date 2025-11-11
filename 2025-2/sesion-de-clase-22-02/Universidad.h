//
// Created by Eric Huiza on 11/7/25.
//

#ifndef SESION_DE_CLASE_22_01_UNIVERSIDAD_H
#define SESION_DE_CLASE_22_01_UNIVERSIDAD_H

#include <fstream>
#include <vector>

#include "Alumno.h"
#include "AlumnoInfo.h"
#include <algorithm>

using namespace std;
class Universidad {
    vector<AlumnoInfo> alumnos;
public:
    void cargarAlumnos(const string& nombreArchivo);
    void reporteAlumnos(const string& nombreArchivo) const;
};


#endif //SESION_DE_CLASE_22_01_UNIVERSIDAD_H