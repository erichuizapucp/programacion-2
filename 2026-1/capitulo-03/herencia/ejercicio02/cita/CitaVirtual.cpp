//
// Created by Eric Huiza on 5/15/26.
//

#include "CitaVirtual.h"
#include <iomanip>

CitaVirtual::CitaVirtual() : Cita() {
	plataforma = nullptr;
	enlace = nullptr;
}

CitaVirtual::CitaVirtual(const CitaVirtual& origin) : Cita(origin) {
	plataforma = nullptr;
	enlace = nullptr;
	*this = origin;
}

char* CitaVirtual::getPlataforma() const {
	return plataforma;
}

char* CitaVirtual::getEnlace() const {
	return enlace;
}

void CitaVirtual::setPlataforma(char* plataforma) {
	setCadena(this->plataforma, plataforma);
}

void CitaVirtual::setEnlace(char* enlace) {
	setCadena(this->enlace, enlace);
}

CitaVirtual& CitaVirtual::operator=(const CitaVirtual& origin) {
	if (this != &origin) {
		Cita::operator=(origin);
		this->setPlataforma(origin.getPlataforma());
		this->setEnlace(origin.getEnlace());
	}
	return *this;
}

ifstream& CitaVirtual::leer(ifstream& archivo) {
	if (!Cita::leer(archivo)) {
		return archivo;
	}

	char* plataforma = leerCadena(archivo);
	char* enlace = leerCadena(archivo, '\n');

	this->setPlataforma(plataforma);
	this->setEnlace(enlace);

	delete[] plataforma;
	delete[] enlace;

	return archivo;
}

ofstream& CitaVirtual::imprimir(ofstream& archivo) const {
	Cita::imprimir(archivo);
	archivo << left << setw(18) << this->plataforma;
	archivo << this->enlace;

	return archivo;
}

CitaVirtual::~CitaVirtual() {
	delete[] plataforma;
	delete[] enlace;
}

ifstream& operator>>(ifstream& archivo, CitaVirtual& cita) {
	return cita.leer(archivo);
}

ofstream& operator<<(ofstream& archivo, const CitaVirtual& cita) {
	return cita.imprimir(archivo);
}
