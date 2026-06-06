//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_CITAVIRTUAL_H
#define EJERCICIO02_CITAVIRTUAL_H

#include "Cita.h"
#include <iomanip>

class CitaVirtual : public Cita {
	char* plataforma;
	char* enlace;
public:
	CitaVirtual();
	CitaVirtual(const CitaVirtual&);

	char* getPlataforma() const;
	char* getEnlace() const;

	void setPlataforma(char*);
	void setEnlace(char*);

	CitaVirtual& operator=(const CitaVirtual&);

	ifstream& leer(ifstream&) override;
	ofstream& imprimir(ofstream&) const override;

	~CitaVirtual() override;
};

#endif //EJERCICIO02_CITAVIRTUAL_H
