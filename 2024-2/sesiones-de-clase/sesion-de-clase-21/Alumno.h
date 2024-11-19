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
    int codigo;
    string nombre;
    string apellido;
    int edad;
    int ciclo;
    double promedio;
protected:
    virtual void cargar(ifstream&);
    virtual void imprimir(ofstream&) const;
public:
    Alumno();
    Alumno(const Alumno& orig);
    virtual ~Alumno();
    
    virtual char getTipo() const = 0;
    virtual Alumno* clonar() = 0;
    int getCodigo() const;
    double getPromedio() const;
    string getNombre() const;
    string getApellido() const;
    
    Alumno& operator=(const Alumno&);
    bool operator<(const Alumno&) const;
    bool operator>(const Alumno&) const;
    
    friend ifstream& operator>>(ifstream&, Alumno&);
    friend ofstream& operator<<(ofstream&, const Alumno&);
};

#endif /* ALUMNO_H */

