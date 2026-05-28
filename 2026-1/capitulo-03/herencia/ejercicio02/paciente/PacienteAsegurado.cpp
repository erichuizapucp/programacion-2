//
// Created by Eric Huiza on 5/15/26.
//

#include "PacienteAsegurado.h"

PacienteAsegurado::PacienteAsegurado() {
	aseguradora = nullptr;
	plan = nullptr;
}

PacienteAsegurado::PacienteAsegurado(const PacienteAsegurado& origin) : PacienteAsegurado() {
	*this = origin;
}

char* PacienteAsegurado::getAseguradora() const {
	return aseguradora;
}

char* PacienteAsegurado::getPlan() const {
	return plan;
}

void PacienteAsegurado::setAseguradora(char* aseguradora) {
	setCadena(this->aseguradora, aseguradora);
}

void PacienteAsegurado::setPlan(char* plan) {
	setCadena(this->plan, plan);
}

PacienteAsegurado& PacienteAsegurado::operator=(const PacienteAsegurado& origin) {
	if (this != &origin) {
		Paciente::operator=(origin);
		this->setAseguradora(origin.getAseguradora());
		this->setPlan(origin.getPlan());
	}
	return *this;
}

ifstream& PacienteAsegurado::leer(ifstream& archivo) {
	if (!Paciente::leer(archivo)) {
		return archivo;
	}

	char* aseguradora = leerCadena(archivo);
	char* plan = leerCadena(archivo, '\n');

	this->setAseguradora(aseguradora);
	this->setPlan(plan);

	delete[] aseguradora;
	delete[] plan;

	return archivo;
}

ofstream& PacienteAsegurado::imprimir(ofstream& archivo) const {
	archivo << "Tipo Paciente: ASEGURADO" << endl;
	Paciente::imprimir(archivo);
	archivo << "Aseguradora: " << this->getAseguradora() << endl;
	archivo << "Plan: " << this->getPlan() << endl;

	return archivo;
}

PacienteAsegurado::~PacienteAsegurado() {
	delete[] this->aseguradora;
	delete[] this->plan;
}

ifstream& operator>>(ifstream& archivo, PacienteAsegurado& paciente) {
	return paciente.leer(archivo);
}

ofstream& operator<<(ofstream& archivo, const PacienteAsegurado& paciente) {
	return paciente.imprimir(archivo);
}

