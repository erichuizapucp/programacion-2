#include "Estudiante.h"

using namespace std;

Estudiante::Estudiante() {
    cout << "Constructor por defecto de Estudiante" << endl;
}

Estudiante::Estudiante(
    int dni, 
    int codigo, 
    const char* nombre, 
    const char* carrera, 
    int annosEstudio, 
    char categoria, 
    int edad, 
    const char** cursos
) : Persona(nombre, dni, edad),
    codigo(codigo), 
    carrera(carrera), 
    annosEstudio(annosEstudio),
    categoria(categoria),
    cursos(cursos)
{
    cout << "Constructor sobrecargado de Estudiante" << endl;
}

void Estudiante::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Estudiante::setCarrera(const char* carrera) {
    this->carrera = carrera;
}

void Estudiante::setAnnosEstudio(int annosEstudio) {
    this->annosEstudio = annosEstudio;
}

void Estudiante::setCategoria(char categoria) {
    this->categoria = categoria;
}

void Estudiante::setCursos(const char** cursos) {
    this->cursos = cursos;
}

void Estudiante::imprimir() {    
    cout << left << setw(10) << "DNI";
    cout << setw(10) << "Código";
    cout << setw(30) << "Nombre"; 
    cout << setw(30) << "Carrera"; 
    cout << setw(20) << "Años de Estudio";
    cout << setw(10) << "Categoría";
    cout << setw(10) << "Edad";
    cout << setw(100) << "Cursos" << endl;;
     
    cout << left << setw(10) << this->dni;
    cout << setw(10) << this->codigo;
    cout << setw(30) << this->nombre;
    cout << setw(30) << this->carrera;
    cout << setw(20) << this->annosEstudio;
    cout << setw(10) << this->categoria;
    cout << setw(10) << this->edad;
    cout << setw(100);
    for (int i = 0; this->cursos[i]; i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << this->cursos[i];
    }
    cout << endl;
}

Estudiante::~Estudiante() {
    cout << "Destructor de Estudiante" << endl;
}