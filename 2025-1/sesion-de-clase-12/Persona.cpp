/* 
 * File:   Persona.cpp
 * Author: erichuiza
 * 
 * Created on April 28, 2025, 5:38 PM
 */

#include "Persona.h"

Persona::Persona() {
}

Persona::Persona(const Persona& orig) {
}

void Persona::hablar() {
    cout << "La persona habla" << endl;
}

void Persona::escuchar() {
    cout << "La persona escucha" << endl;
}

void Persona::correr() {
    cout << "La persona corre" << endl;
}

void Persona::dormir() {
    cout << "La persona duerme" << endl;
}

Persona::~Persona() {
}