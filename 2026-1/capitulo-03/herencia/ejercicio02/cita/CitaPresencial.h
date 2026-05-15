//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_CITAPRESENCIAL_H
#define EJERCICIO02_CITAPRESENCIAL_H

#include "Cita.h"

class CitaPresencial : public Cita {
	char* consultorio;
	char* sede;
public:
	CitaPresencial();
	CitaPresencial(const CitaPresencial&);

	char* getConsultorio() const;
	char* getSede() const;

	void setConsultorio(char*);
	void setSede(char*);

	CitaPresencial& operator=(const CitaPresencial&);

	ifstream& leer(ifstream&);
	ofstream& imprimir(ofstream&) const;

	~CitaPresencial();
};

ifstream& operator>>(ifstream&, CitaPresencial&);
ofstream& operator<<(ofstream&, const CitaPresencial&);


#endif //EJERCICIO02_CITAPRESENCIAL_H
