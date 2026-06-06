//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_PERSONA_H
#define EJERCICIO02_PERSONA_H

#include "Registro.h"

class Persona : public Registro {
	int dni;
	char* nombre;
protected:
	ifstream& leer(ifstream&) override;
	ofstream& imprimir(ofstream&) const override;
public:
	Persona();
	Persona(const Persona&);

	int getDni() const;
	char* getNombre() const;

	void setDni(int);
	void setNombre(char*);

	Persona& operator=(const Persona&);

	virtual ~Persona();
};

#endif //EJERCICIO02_PERSONA_H

