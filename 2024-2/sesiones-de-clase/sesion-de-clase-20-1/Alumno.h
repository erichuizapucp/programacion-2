/* 
 * File:   Alumno.h
 * Author: erichuiza
 *
 * Created on November 11, 2024, 3:17 PM
 */

#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

class Alumno {
private:
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

    virtual Alumno* clonar() = 0;
    
    void operator=(const Alumno&);
    friend void operator>>(ifstream&, Alumno&);
    friend void operator<<(ofstream&, const Alumno&);
};

#endif /* ALUMNO_H */

