//
// Created by Eric Huiza on 5/15/26.
//

#include "CitaPresencial.h"

CitaPresencial::CitaPresencial() {
	consultorio = nullptr;
	sede = nullptr;
}

CitaPresencial::CitaPresencial(const CitaPresencial& origin) : CitaPresencial() {
	*this = origin;
}

char* CitaPresencial::getConsultorio() const {
	return consultorio;
}

char* CitaPresencial::getSede() const {
	return sede;
}

void CitaPresencial::setConsultorio(char* consultorio) {
	setCadena(this->consultorio, consultorio);
}

void CitaPresencial::setSede(char* sede) {
	setCadena(this->sede, sede);
}

CitaPresencial& CitaPresencial::operator=(const CitaPresencial& origin) {
	if (this != &origin) {
		Cita::operator=(origin);
		this->setConsultorio(origin.getConsultorio());
		this->setSede(origin.getSede());
	}
	return *this;
}

ifstream& CitaPresencial::leer(ifstream& archivo) {
	if (!Cita::leer(archivo)) {
		return archivo;
	}

	char* consultorio = leerCadena(archivo);
	char* sede = leerCadena(archivo, '\n');

	this->setConsultorio(consultorio);
	this->setSede(sede);

	delete[] consultorio;
	delete[] sede;

	return archivo;
}

ofstream& CitaPresencial::imprimir(ofstream& archivo) const {
	Cita::imprimir(archivo);
	archivo << left << setw(20) << getConsultorio();
	archivo << getSede();
	return archivo;
}

CitaPresencial::~CitaPresencial() {
	delete[] consultorio;
	delete[] sede;
}

ifstream& operator>>(ifstream& archivo, CitaPresencial& cita) {
	return cita.leer(archivo);
}

ofstream& operator<<(ofstream& archivo, const CitaPresencial& cita) {
	return cita.imprimir(archivo);
}
