/* 
 * File:   Alumno.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 10:32 AM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class Alumno {
private:
    char tipo;
    string nombre;
    string apellido;
    int edad;
    int ciclo;
    vector<string> cursos;
protected:
    virtual void cargar(ifstream&);
    virtual void imprimir(ofstream&) const;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    
    virtual char getTipo() const = 0;
    virtual Alumno* clonar() = 0;
    void operator=(const Alumno&);
    friend void operator>>(ifstream&, Alumno&);
    friend void operator<<(ofstream&, const Alumno&);
};

#endif /* ALUMNO_H */

