/* 
 * File:   AlumnoIntercambio.cpp
 * Author: erichuiza
 * 
 * Created on November 11, 2024, 10:18 AM
 */

#include "AlumnoIntercambio.h"

AlumnoIntercambio::AlumnoIntercambio() : Alumno() {
    paisOrigen = {};
    universidadOrigen = {};
    duracion = {};
}

AlumnoIntercambio::AlumnoIntercambio(const AlumnoIntercambio& orig) : Alumno(orig) {
    *this = orig;
}

char AlumnoIntercambio::getTipo() const {
    return 'I';
}

Alumno* AlumnoIntercambio::clonar() {
    return new AlumnoIntercambio(*this);
}

void AlumnoIntercambio::cargar(ifstream& archivo) {
    Alumno::cargar(archivo);
    getline(archivo, paisOrigen, ',');
    getline(archivo, universidadOrigen, ',');
    archivo >> duracion;
    archivo.ignore();
}

void AlumnoIntercambio::imprimir(ofstream& archivo) const {
    Alumno::imprimir(archivo);
    archivo << setw(10) << paisOrigen << setw(20) << universidadOrigen << setw(5) << duracion << endl;
}

//R,Juan,Pérez,20,3,Matematicas Calculo-Fisica,2021
//I,Sarah,Smith,22,2,Historia-Latina Cultura-Moderna,Estados-Unidos,Universidad-de-California,6
//R,Ana,Gómez,19,1,Introduccion-a-la-Ingenieria Algebra-Elemental,2023
//I,Marco,Rossi,21,4,Filosofia Europea-Politica-Economica,Italia,Universidad-de-Roma,12
//R,Luis,Martínez,22,5,Calculo-Diferencial Probabilidad-Estadistica,2020
//I,Emily,Johnson,23,3,Literatura-Francesa Historia-Europea,Francia,Universidad-de-Paris,4
//R,Carlos,Lopez,20,2,Programacion-Fundamentos Introduccion-a-Bases-de-Datos,2022

void AlumnoIntercambio::operator=(const AlumnoIntercambio& orig) {
    Alumno::operator =(orig);
    paisOrigen = orig.paisOrigen;
    universidadOrigen = orig.universidadOrigen;
    duracion = orig.duracion;
}

AlumnoIntercambio::~AlumnoIntercambio() {
}

