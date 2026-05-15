//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_PERSONA_H
#define EJERCICIO02_PERSONA_H

#include "Registro.h"

class Persona : public Registro {
	int dni;
	char* nombre;
public:
	Persona();
	Persona(const Persona&);

	int getDni() const;
	char* getNombre() const;

	void setDni(int);
	void setNombre(char*);

	Persona& operator=(const Persona&);

	ifstream& leer(ifstream&);
	ofstream& imprimir(ofstream&) const;

	~Persona();
};

ifstream& operator>>(ifstream&, Persona&);
ofstream& operator<<(ofstream&, const Persona&);

#endif //EJERCICIO02_PERSONA_H

