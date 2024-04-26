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
    char** cursos) 
    : 
    Persona(nombre, dni, edad),
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

void Estudiante::setCursos(char** cursos) {
    this->cursos = cursos;
}

void Estudiante::imprimir() {
    cout << "DNI: " << this->dni << endl;
    cout << "Codigo: " << this->codigo << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Carrera: " << this->carrera << endl;
    cout << "Años de Estudio: " << this->annosEstudio << endl;
    cout << "Categoría: " << this->categoria << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Cursos: ";
    for (int i = 0; i < 3; i++) {
        cout << this->cursos[i] << " ";
    }
}

Estudiante::~Estudiante() {
    cout << "Destructor de Estudiante" << endl;
}