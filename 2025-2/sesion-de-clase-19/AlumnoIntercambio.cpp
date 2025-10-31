//
// Created by Eric Huiza on 10/24/25.
//

#include "AlumnoIntercambio.h"

AlumnoIntercambio::AlumnoIntercambio() : Alumno() {
    paisOrigen = nullptr;
    duracion = 0;
}

AlumnoIntercambio::AlumnoIntercambio(int codigo,
    char* nombre, double creditos, char* paisOrigen, int duracion)
    : Alumno(codigo, nombre, creditos)
{
    this->paisOrigen = nullptr;
    setCadena(this->paisOrigen, paisOrigen);
    this->duracion = duracion;
}

AlumnoIntercambio::AlumnoIntercambio(const AlumnoIntercambio& origen)
    : Alumno(origen) {
    this->paisOrigen = nullptr;
    *this = origen;
}

char* AlumnoIntercambio::getPaisOrigen() const {
    return paisOrigen;
}

int AlumnoIntercambio::getDuracion() const {
    return duracion;
}

void AlumnoIntercambio::setPaisOrigen(char* paisOrigen) {;
    setCadena(this->paisOrigen, paisOrigen);
}

void AlumnoIntercambio::setDuracion(int duracion) {
    this->duracion = duracion;
}

AlumnoIntercambio& AlumnoIntercambio::operator=(const AlumnoIntercambio& origen) {
    Alumno::operator=(origen);
    setCadena(this->paisOrigen, origen.paisOrigen);
    setDuracion(origen.duracion);
}

istream& AlumnoIntercambio::leer(istream& archivo) {
    return archivo;
}

ostream& AlumnoIntercambio::imprimir(ostream& archivo) const {
    Alumno::imprimir(archivo);
    archivo << "Pais de Origen: " << paisOrigen << endl;
    archivo << "Duracion: " << duracion << endl;

    return archivo;
}

AlumnoIntercambio::~AlumnoIntercambio() {
    cout << "Destructor Derivada" << endl;
    delete[] paisOrigen;
}