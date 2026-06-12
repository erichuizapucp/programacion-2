#include <iostream>

#include "Alumno.h"

using namespace std;

int main() {
    Alumno alumno;
    alumno.setCodigo(12345);
    alumno.setNombre("Juan Perez");
    alumno.setEdad(20);
    alumno.setCiclo(5);
    alumno.setFacultad("Alumno");

    Curso programacion2;
    programacion2.setCodigo(101);
    programacion2.setNombre("Programacion 2");
    programacion2.setCiclo(5);

    Curso algoritmia;
    algoritmia.setCodigo(102);
    algoritmia.setNombre("Algoritmia");
    algoritmia.setCiclo(5);

    vector<Curso> cursos = alumno.getCursos();
    cursos.push_back(programacion2);
    cursos.push_back(algoritmia);

    alumno.setCursos(cursos);

    cout << "Codigo: " << alumno.getCodigo() << endl;
    cout << "Nombre: " << alumno.getNombre() << endl;
    cout << "Edad: " << alumno.getEdad() << endl;
    cout << "Ciclo: " << alumno.getCiclo() << endl;
    cout << "Facultad: " << alumno.getFacultad() << endl;

    cout << "Cursos:" << endl;

    vector<Curso> cursosAlumno = alumno.getCursos();
    for (auto it = cursosAlumno.begin(); it != cursosAlumno.end(); ++it) {
        cout << "  Codigo: " << it->getCodigo() << endl;
        cout << "  Nombre: " << it->getNombre() << endl;
        cout << "  Ciclo: " << it->getCiclo() << endl;
    }

    return 0;
}
