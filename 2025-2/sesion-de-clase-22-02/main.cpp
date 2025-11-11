#include <iostream>

#include "Universidad.h"

using namespace std;
int main() {
    Universidad u;
    u.cargarAlumnos("alumnos.csv");
    u.reporteAlumnos("reporte.txt");

    return 0;
}