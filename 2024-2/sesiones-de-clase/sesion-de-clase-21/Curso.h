/* 
 * File:   Curso.h
 * Author: erichuiza
 *
 * Created on November 17, 2024, 6:10 PM
 */

#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Curso {
private:
    int codigo;
    string nombre;
    int creditos;
    int capacidad;
public:
    Curso();
    Curso(const Curso& orig);
    virtual ~Curso();
    
    int getCodigo() const;
    int getCapacidad() const;
    string getNombre() const;
    
    Curso& operator=(const Curso&);
    bool operator<(const Curso&) const;
    bool operator>(const Curso&) const;
    
    friend ifstream& operator>>(ifstream&, Curso&);
    friend ofstream& operator<<(ofstream&, const Curso&);
};

#endif /* CURSO_H */

