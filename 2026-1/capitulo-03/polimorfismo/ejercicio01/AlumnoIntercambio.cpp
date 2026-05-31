//
// Created by Eric Huiza on 5/30/26.
//

#include "AlumnoIntercambio.h"

AlumnoIntercambio::AlumnoIntercambio() {
    this->estancia = 0;
}
AlumnoIntercambio::AlumnoIntercambio(int dni, int edad, int ciclo,
    int creditos, int estancia) : Alumno(dni, edad, ciclo, creditos) {

    this->estancia = estancia;
}

void AlumnoIntercambio::imprimir() const {
    cout << "DNI: " << getDni() << endl;
    cout << "Edad: " << getEdad() << endl;
    cout << "Codigo: " << getCodigo() << endl;
    cout << "Ciclo: " << getCiclo() << endl;
    cout << "Estancia en meses: " << estancia << endl;
}