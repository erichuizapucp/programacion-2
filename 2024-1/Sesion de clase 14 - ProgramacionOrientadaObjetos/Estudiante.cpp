#include "Estudiante.h"

using namespace std;

Estudiante::Estudiante(
) : Persona(),
    codigo(0), 
    carrera(nullptr), 
    annosEstudio(0), 
    categoria(0), 
    cursos(nullptr) {
    cout << "Constructor por defecto de Estudiante" << endl;
}

Estudiante::Estudiante(
    int dni, 
    int codigo, 
    char* nombre, 
    int edad, 
    double altura, 
    double peso, 
    Nacionalidad nacionalidad, 
    char* carrera, 
    int annosEstudio, 
    char categoria, 
    char** cursos
) : Persona(dni, nombre, edad, altura, peso, nacionalidad),
    codigo(codigo), 
    carrera(carrera), 
    annosEstudio(annosEstudio),
    categoria(categoria),
    cursos(cursos) {
    cout << "Constructor sobrecargado de Estudiante" << endl;
}

void Estudiante::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Estudiante::setCarrera(char* carrera) {
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

char** Estudiante::leerCursos(char* &cadenaCursos) {
    int num = 0;
    int capacidad = 0;
    char* curso;
    char** cursos = nullptr;
    
    istringstream ss(cadenaCursos);
    
    while(!ss.eof()) {
        curso = leerCadena(ss);
        if (num == capacidad) {
            incrementMemorySpaces(cursos, num, capacidad);
        }
        cursos[num] = curso;
        num++;
    } 
    
    return cursos;
}

void Estudiante::cargar(ifstream &archivo) {
    Persona::cargar(archivo);
    
    char comma;
    this->carrera = leerCadena(archivo);
    archivo >> this->annosEstudio >> comma;
    archivo >> this->categoria >> comma;
    
    char* cadenaCursos = leerCadena(archivo, '\n');
    this->cursos = leerCursos(cadenaCursos);
}

void Estudiante::imprimirCursos(ostream &os) {
    os << "Cursos: ";
    for (int i = 0; this->cursos[i] != nullptr; i++) {
        if (i > 0) {
            os << ", ";
        }
        os << this->cursos[i];
    }
    os << endl;
}

void Estudiante::imprimir(ostream &os) {
    Persona::imprimir();
    
    if (codigo > 0) {
        os << "Código: " << codigo << endl;
    }
    if (carrera != nullptr) {
        os << "Carrera: " << carrera << endl;
    }
    if (annosEstudio > 0) {
        os << "Años de estudio: " << annosEstudio << endl;
    }
    if (categoria > 0) {
        os << "Categoría: " << categoria << endl;
    }
    
    if (cursos != nullptr) {
        imprimirCursos(os);
    }
    
    if (nacionalidad != Nacionalidad::Peru) {
        os << "El estudiante es extranjero." << endl;
    }
    
    os << endl;
}

void Estudiante::grabarCursos(ofstream &archivo) {
    for (int i = 0; this->cursos[i] != nullptr; i++) {
        if (i > 0) {
            archivo << ",";
        }
        archivo << this->cursos[i];
    }
}

void Estudiante::grabar(ofstream &archivo) {
    Persona::grabar(archivo);
    archivo << carrera << "," << annosEstudio << "," << categoria << ",";
    grabarCursos(archivo);
    archivo << endl;
}

Estudiante::~Estudiante() {
    cout << "Destructor de Estudiante" << endl;
}